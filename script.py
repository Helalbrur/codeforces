"""
Codeforces Auto-Sync (API + browser, minimal overhead)
Uses official API for metadata, and a single persistent browser for source code.
"""

import re, os, json, time, random, html, hashlib, hmac, urllib.parse
from bs4 import BeautifulSoup
from dotenv import load_dotenv
from datetime import datetime, timezone
from git import Repo
import requests

import undetected_chromedriver as uc
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import subprocess


# ================= CONFIG =================
_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
load_dotenv(os.path.join(_SCRIPT_DIR, ".env"))

CF_HANDLE     = os.getenv("CF_HANDLE", "Helaluddin_brur")
CF_API_KEY    = os.getenv("CF_API_KEY")
CF_API_SECRET = os.getenv("CF_API_SECRET")
REPO_PATH     = os.getenv("CF_REPO_PATH")
CF_BASE       = "https://codeforces.com"
CF_API_URL    = "https://codeforces.com/api"

HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
}

# Tuning knobs
MAX_FETCH_RETRIES = 3   # attempts per submission before giving up
DELAY_MIN         = 3.0 # seconds between page loads (random between min/max)
DELAY_MAX         = 6.0
CRASH_THRESHOLD   = 3   # consecutive failures before force-restarting browser


# ============================================================
# API signing
# ============================================================
def cf_api_signed(method_name, params):
    if not CF_API_KEY or not CF_API_SECRET:
        raise ValueError("CF_API_KEY and CF_API_SECRET must be set in .env")
    params = params.copy()
    params["apiKey"] = CF_API_KEY
    params["time"]   = str(int(time.time()))
    sorted_keys = sorted(params.keys())
    encoded_parts = [f"{k}={urllib.parse.quote(str(params[k]), safe='')}" for k in sorted_keys]
    query_string_for_sig = "&".join(encoded_parts)
    rand     = "123456"
    sign_str = f"{rand}/{method_name}?{query_string_for_sig}#{CF_API_SECRET}"
    sig      = hashlib.sha512(sign_str.encode()).hexdigest()
    params["apiSig"] = rand + sig
    url  = f"{CF_API_URL}/{method_name}"
    resp = requests.get(url, params=params, headers=HEADERS, timeout=30)
    if resp.status_code != 200:
        print(f"❌ API error (HTTP {resp.status_code}): {resp.text[:500]}")
        resp.raise_for_status()
    data = resp.json()
    if data.get("status") != "OK":
        raise RuntimeError(f"CF API error: {data.get('comment')}")
    return data["result"]


# ============================================================
# Fetch metadata
# ============================================================
def fetch_submissions():
    print(f"  📡 Fetching submissions for @{CF_HANDLE} via API (signed)…")
    try:
        result = cf_api_signed("user.status", {"handle": CF_HANDLE, "from": 1, "count": 10000})
    except Exception as e:
        print(f"  ⚠ Signed API failed: {e}\n  → Trying unsigned API…")
        resp = requests.get(f"{CF_API_URL}/user.status",
                            params={"handle": CF_HANDLE, "from": 1, "count": 10000}, timeout=30)
        resp.raise_for_status()
        data = resp.json()
        if data.get("status") != "OK":
            raise RuntimeError(f"Unsigned API error: {data.get('comment')}")
        result = data["result"]
    accepted = [s for s in result if s.get("verdict") == "OK"]
    print(f"  Total: {len(result)}  |  ✅ Accepted: {len(accepted)}")
    return accepted

def fetch_user_info():
    result = {"info": {}, "rating_history": []}
    try:
        info = cf_api_signed("user.info", {"handles": CF_HANDLE})[0]
        result["info"] = info
        print(f"  👤 Rating: {info.get('rating','N/A')}  Rank: {info.get('rank','N/A')}")
    except Exception as e:
        print(f"  ⚠ user.info failed: {e}")
    try:
        history = cf_api_signed("user.rating", {"handle": CF_HANDLE})
        result["rating_history"] = history
        print(f"  📈 Contests: {len(history)}")
    except Exception as e:
        print(f"  ⚠ user.rating failed: {e}")
    return result


# ============================================================
# Browser — persistent instance with auto-restart on crash
# ============================================================
GYM_THRESHOLD = 100000

def submission_url(sub):
    cid = sub.get("contestId")
    sid = sub.get("id")
    if cid is None:
        return f"{CF_BASE}/problemset/submission/{CF_HANDLE}/{sid}"
    if cid >= GYM_THRESHOLD:
        return f"{CF_BASE}/gym/{cid}/submission/{sid}"
    return f"{CF_BASE}/contest/{cid}/submission/{sid}"

_driver = None

def get_chrome_version():
    for cmd in ["google-chrome", "chromium-browser"]:
        try:
            out = subprocess.check_output([cmd, "--version"], stderr=subprocess.DEVNULL).decode()
            m   = re.search(r'(\d+)\.', out)
            if m:
                return int(m.group(1))
        except Exception:
            pass
    return None

def kill_browser():
    """Quit the global browser if it is running."""
    global _driver
    if _driver is not None:
        try:
            _driver.quit()
        except Exception:
            pass
        _driver = None

def get_browser():
    """Return (or launch) the global browser, asking for login if needed."""
    global _driver
    if _driver is not None:
        return _driver

    print("  🔄 Launching browser…")
    options = uc.ChromeOptions()
    user_data_dir = os.path.join(os.getcwd(), "chrome_profile")
    options.add_argument(f"--user-data-dir={user_data_dir}")
    options.add_argument("--no-sandbox")
    options.add_argument("--disable-dev-shm-usage")
    options.add_argument("--window-size=1280,900")
    options.add_argument("--disable-blink-features=AutomationControlled")
    options.add_argument("--js-flags=--max-old-space-size=512")  # cap memory

    chrome_version = get_chrome_version()
    if chrome_version:
        print(f"  🟡 Detected Chrome {chrome_version}")
        _driver = uc.Chrome(options=options, headless=False,
                            use_subprocess=True, version_main=chrome_version)
    else:
        _driver = uc.Chrome(options=options, headless=False, use_subprocess=True)

    _driver.get(CF_BASE)
    time.sleep(5)

    if "login" in _driver.current_url.lower() or "enter" in _driver.page_source.lower():
        print("  ⚠️ Please log in to Codeforces in the browser, then press Enter.")
        input("  Press Enter when done…")
        _driver.get(CF_BASE)

    print("  ✅ Browser ready")
    return _driver


# ============================================================
# Failed-IDs persistence  (.failed_ids.json in REPO_PATH)
# ============================================================
def failed_ids_path():
    return os.path.join(REPO_PATH, ".failed_ids.json")

def load_failed_ids():
    p = failed_ids_path()
    if os.path.exists(p):
        with open(p) as f:
            return set(json.load(f))
    return set()

def save_failed_ids(failed: set):
    with open(failed_ids_path(), "w") as f:
        json.dump(sorted(failed), f, indent=2)


# ============================================================
# fetch_code — retries + auto browser restart on crash
# ============================================================
_consecutive_failures = 0

def fetch_code(sub):
    """
    Fetch source code for a submission.
    - Retries up to MAX_FETCH_RETRIES times.
    - Detects Chrome crash (blank error + raw stacktrace) and restarts the browser.
    - Restarts proactively after CRASH_THRESHOLD consecutive failures.
    """
    global _consecutive_failures

    url = submission_url(sub)
    sid = sub.get("id")

    for attempt in range(1, MAX_FETCH_RETRIES + 1):
        try:
            driver = get_browser()
            delay  = random.uniform(DELAY_MIN, DELAY_MAX)
            print(f"    → Attempt {attempt}/{MAX_FETCH_RETRIES}  (delay {delay:.1f}s)")
            time.sleep(delay)

            driver.get(url)
            elem = WebDriverWait(driver, 20).until(
                EC.presence_of_element_located(
                    (By.CSS_SELECTOR, "#program-source-text, pre.prettyprint, .linenums")
                )
            )
            code = elem.text.strip()

            # Fallback: any <pre> with content
            if len(code) <= 20:
                for pre in driver.find_elements(By.TAG_NAME, "pre"):
                    code = pre.text.strip()
                    if len(code) > 20:
                        break

            if len(code) > 20:
                _consecutive_failures = 0
                save_code_in_txt(sub, code)
                return code

            print(f"    ✗ No code content found (attempt {attempt})")
            _consecutive_failures += 1

        except Exception as e:
            err = str(e).strip()
            # A Chrome crash produces a blank message with only a native stacktrace
            is_crash = (
                "Stacktrace" in err or
                "chrome not reachable" in err.lower() or
                "session deleted" in err.lower() or
                len(err) < 10
            )
            if is_crash:
                print(f"    💥 Chrome crashed (attempt {attempt}) — restarting browser…")
                kill_browser()
                time.sleep(6)
            else:
                print(f"    ⚠ Error attempt {attempt}: {err[:140]}")

            _consecutive_failures += 1

        # Proactive restart after too many consecutive failures
        if _consecutive_failures >= CRASH_THRESHOLD:
            print(f"    🔁 {_consecutive_failures} consecutive failures — force-restarting browser…")
            kill_browser()
            time.sleep(10)
            _consecutive_failures = 0

        if attempt < MAX_FETCH_RETRIES:
            time.sleep(random.uniform(3.0, 5.0))

    print(f"    ❌ Giving up on {sid} after {MAX_FETCH_RETRIES} attempts — will retry next run")
    return None


# ============================================================
# save_code_in_txt — with absolute-path debug print
# ============================================================
def save_code_in_txt(sub, code):
    sid = sub.get("id")
    if not code:
        return
    try:
        folder   = os.path.join(REPO_PATH, "Submission_Codes")
        os.makedirs(folder, exist_ok=True)
        filepath = os.path.join(folder, f"{sid}.txt")
        print(f"    → Saving to: {os.path.abspath(filepath)}")
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(code)
        if os.path.exists(filepath):
            print(f"    ✅ Code saved for {sid} ({os.path.getsize(filepath)} bytes)")
        else:
            print(f"    ❌ File NOT found after write — check REPO_PATH / permissions!")
    except Exception as e:
        print(f"    ⚠ Error saving code for {sid}: {e}")


# ============================================================
# Resume helpers
# ============================================================
def load_already_saved_ids():
    folder = os.path.join(REPO_PATH, "Submission_Codes")
    if not os.path.isdir(folder):
        return set()
    saved = {f[:-4] for f in os.listdir(folder) if f.endswith(".txt") and f[:-4].isdigit()}
    print(f"  📂 {len(saved)} submission(s) already saved in Submission_Codes/")
    return saved


# ============== TRACKER ==============
def tracker_path():
    return os.path.join(REPO_PATH, ".sync_tracker.json")

def load_tracker():
    p = tracker_path()
    if os.path.exists(p):
        with open(p) as f:
            return json.load(f)
    return {"synced_ids": [], "problems": {}, "counts": {}}

def save_tracker(tracker):
    with open(tracker_path(), "w") as f:
        json.dump(tracker, f, indent=2)


# ============== SAVE CONTEST STATS ==============
def save_contest_stats(user_data, repo_path):
    info    = user_data.get("info", {})
    history = user_data.get("rating_history", [])
    if not info and not history:
        return
    folder = os.path.join(repo_path, "Contests")
    os.makedirs(folder, exist_ok=True)
    rows = ""; peak = 0
    for i, r in enumerate(history):
        o  = r.get("oldRating", 0); n = r.get("newRating", 0); d = n - o
        ds = datetime.fromtimestamp(r.get("ratingUpdateTimeSeconds", 0),
                                    tz=timezone.utc).strftime("%Y-%m-%d")
        peak = max(peak, n)
        rows += (f"| {i+1} | [{r.get('contestName','?')}]({CF_BASE}/contest/{r.get('contestId','')}) "
                 f"| {r.get('rank','—')} | {o} | {n} | {'🟢 +' if d>=0 else '🔴 '}{abs(d)} | {ds} |\n")
    with open(os.path.join(folder, "README.md"), "w", encoding="utf-8") as f:
        f.write(f"# ⚡ Contest History — @{CF_HANDLE}\n\n"
                f"🔗 [{CF_BASE}/profile/{CF_HANDLE}]({CF_BASE}/profile/{CF_HANDLE})\n\n"
                f"## 🏆 Standing\n\n| Field | Value |\n|-------|-------|\n"
                f"| Current Rating | **{info.get('rating','Unrated')}** |\n"
                f"| Peak Rating | **{info.get('maxRating', peak)}** |\n"
                f"| Current Rank | {info.get('rank','Unrated')} |\n"
                f"| Peak Rank | {info.get('maxRank','Unrated')} |\n"
                f"| Contests | {len(history)} |\n\n"
                f"## 📈 Rating History\n\n"
                f"| # | Contest | Rank | Old | New | Change | Date |\n"
                f"|---|---------|------|-----|-----|--------|------|\n{rows}")
    for r in history:
        cid  = r.get("contestId","")
        safe = re.sub(r'[^\w\s-]', '', r.get("contestName","?")).replace(" ","_")[:60]
        o    = r.get("oldRating",0); n = r.get("newRating",0); d = n - o
        ds   = datetime.fromtimestamp(r.get("ratingUpdateTimeSeconds",0),
                                      tz=timezone.utc).strftime("%Y-%m-%d")
        with open(os.path.join(folder, f"{cid}_{safe}.md"), "w", encoding="utf-8") as f:
            f.write(f"# {r.get('contestName','?')}\n\n| Field | Value |\n|-------|-------|\n"
                    f"| Date | {ds} |\n| Rank | {r.get('rank','—')} |\n"
                    f"| Old Rating | {o} |\n| New Rating | {n} |\n"
                    f"| Change | {'+'if d>=0 else ''}{d} |\n"
                    f"| Link | [Contest]({CF_BASE}/contest/{cid}) |\n"
                    f"| Standing | [My Result]({CF_BASE}/contest/{cid}/standings/participant/handle/{CF_HANDLE}) |\n")
    print(f"  📄 Contests/ saved ({len(history)} contests)")


# ============== MAPPINGS ==============
CATEGORY_MAP = {
    "dp": "DynamicProgramming", "greedy": "Greedy",
    "graphs": "Graph", "trees": "Tree",
    "math": "Math", "number theory": "Math", "combinatorics": "Math",
    "geometry": "Geometry", "strings": "String", "sortings": "Sorting",
    "binary search": "BinarySearch", "two pointers": "TwoPointers",
    "data structures": "DataStructures", "implementation": "Implementation",
    "brute force": "BruteForce", "constructive algorithms": "Constructive",
    "dfs and similar": "Graph", "bfs": "Graph",
    "shortest paths": "Graph", "flows": "Graph",
    "divide and conquer": "DivideAndConquer", "hashing": "HashTable",
    "matrices": "Matrix", "probabilities": "Math", "games": "GameTheory",
    "2-sat": "Graph", "meet-in-the-middle": "DivideAndConquer",
    "fft": "Math", "string suffix structures": "String",
    "interactive": "Interactive", "bitmasks": "BitManipulation",
    "ternary search": "BinarySearch", "expression parsing": "String",
}
LANG_FOLDER_MAP = {
    "python3": "Python", "pypy3": "Python", "python2": "Python", "pypy2": "Python",
    "gnu c++17": "CPP", "gnu c++14": "CPP", "gnu c++20 (64)": "CPP",
    "gnu c++11": "CPP", "msvc c++": "CPP", "clang++17 windowed": "CPP", "gnu c11": "CPP",
    "java 8": "Java", "java 11": "Java", "java 17": "Java",
    "javascript": "JavaScript", "node.js": "JavaScript",
    "go": "Go", "rust 2021": "Rust", "kotlin": "Kotlin",
    "haskell": "Haskell", "ruby": "Ruby", "scala": "Scala",
    "c#": "CSharp", "php": "PHP",
}
LANG_EXT = {
    "python3": "py", "pypy3": "py", "python2": "py", "pypy2": "py",
    "gnu c++17": "cpp", "gnu c++14": "cpp", "gnu c++20 (64)": "cpp",
    "gnu c++11": "cpp", "msvc c++": "cpp", "clang++17 windowed": "cpp", "gnu c11": "c",
    "java 8": "java", "java 11": "java", "java 17": "java",
    "javascript": "js", "node.js": "js", "go": "go",
    "rust 2021": "rs", "kotlin": "kt", "haskell": "hs",
    "ruby": "rb", "scala": "scala", "c#": "cs", "php": "php",
}
LANG_COMMENT = {
    "py": "#", "js": "//", "cpp": "//", "c": "//",
    "java": "//", "cs": "//", "go": "//", "rs": "//",
    "kt": "//", "hs": "--", "rb": "#", "scala": "//", "php": "//",
}


# ============== BUILD & SAVE SOLUTION ==============
def build_file(sub, code, attempt_num, ext):
    c = LANG_COMMENT.get(ext, "#")
    p = sub.get("problem", {})
    cid = sub.get("contestId",""); idx = p.get("index","")
    date = datetime.fromtimestamp(int(sub.get("creationTimeSeconds", time.time())),
                                  tz=timezone.utc).strftime("%Y-%m-%d")
    return (f"{c} {p.get('name','?')} (CF {cid}{idx})\n"
            f"{c} Rating  : {p.get('rating','?')}\n"
            f"{c} Tags    : {', '.join(p.get('tags',[]))}\n"
            f"{c} Lang    : {sub.get('programmingLanguage','')}\n"
            f"{c} Solved  : {date}\n"
            f"{c} Attempt : #{attempt_num}\n"
            f"{c} URL     : {CF_BASE}/contest/{cid}/problem/{idx}\n\n") + code

def save_solution(sub, code, attempt_num):
    p    = sub.get("problem", {})
    tags = p.get("tags", [])
    cid  = sub.get("contestId","0"); idx = p.get("index","A")
    name = p.get("name","Unknown")
    category = "Misc"
    for tag in tags:
        if tag.lower() in CATEGORY_MAP:
            category = CATEGORY_MAP[tag.lower()]; break
    prob_key    = f"{cid}{idx}"
    title       = name.replace(" ","_").replace("/","_")
    folder_name = f"{prob_key}_{title}"
    lang_raw    = sub.get("programmingLanguage","").lower()
    ext         = LANG_EXT.get(lang_raw, "txt")
    filename    = "solution" if attempt_num == 1 else f"solution_{attempt_num}"
    content     = build_file(sub, code, attempt_num, ext)
    date_str    = datetime.fromtimestamp(int(sub.get("creationTimeSeconds", time.time())),
                                         tz=timezone.utc).strftime("%Y-%m-%d")
    lang_norm   = lang_raw.replace(" ","_").replace(".","")
    lf          = LANG_FOLDER_MAP.get(lang_raw, lang_raw.replace(" ","").capitalize())

    for base, extra in [
        (os.path.join(REPO_PATH, "DSA", category, folder_name, lang_norm), True),
        (os.path.join(REPO_PATH, "Programming Languages", lf, folder_name), False),
    ]:
        os.makedirs(base, exist_ok=True)
        with open(os.path.join(base, f"{filename}.{ext}"), "w", encoding="utf-8") as f:
            f.write(content)
        if extra:
            _write_problem_readme(os.path.dirname(base), sub, category, date_str)
            print(f"    ✅ DSA  → DSA/{category}/{folder_name}/{lang_norm}/{filename}.{ext}")
        else:
            _write_pl_readme(base, sub, date_str, lf)
            print(f"    ✅ Lang → Programming Languages/{lf}/{folder_name}/{filename}.{ext}")
    return lang_norm, lf, category

def _write_problem_readme(folder, sub, category, date):
    p = sub.get("problem",{}); cid = sub.get("contestId",""); idx = p.get("index","")
    rows = ""
    if os.path.isdir(folder):
        for ld in sorted(os.listdir(folder)):
            lp = os.path.join(folder, ld)
            if not os.path.isdir(lp): continue
            for s in sorted(f for f in os.listdir(lp) if f.startswith("solution")):
                rows += f"| `{ld}` | [{s}](./{ld}/{s}) |\n"
    with open(os.path.join(folder,"README.md"),"w",encoding="utf-8") as f:
        f.write(f"# {p.get('name','?')} (CF {cid}{idx})\n\n"
                f"| Field | Value |\n|-------|-------|\n"
                f"| Rating | {p.get('rating','?')} |\n| Category | {category} |\n"
                f"| Tags | {', '.join(f'`{t}`' for t in p.get('tags',[]))} |\n"
                f"| Solved | {date} |\n"
                f"| Link | [CF]({CF_BASE}/contest/{cid}/problem/{idx}) |\n\n"
                f"## Solutions\n\n| Language | File |\n|----------|------|\n{rows}")

def _write_pl_readme(folder, sub, date, lang_name):
    p = sub.get("problem",{}); cid = sub.get("contestId",""); idx = p.get("index","")
    rows = "".join(f"| [{s}](./{s}) |\n"
                   for s in sorted(f for f in os.listdir(folder) if f.startswith("solution")))
    with open(os.path.join(folder,"README.md"),"w",encoding="utf-8") as f:
        f.write(f"# {p.get('name','?')}\n\n| Field | Value |\n|-------|-------|\n"
                f"| Language | {lang_name} |\n"
                f"| Tags | {', '.join(f'`{t}`' for t in p.get('tags',[]))} |\n"
                f"| Solved | {date} |\n"
                f"| Link | [CF]({CF_BASE}/contest/{cid}/problem/{idx}) |\n\n"
                f"## Attempts\n\n| File |\n|------|\n{rows}")

def _gen_lang_indexes():
    pl_root = os.path.join(REPO_PATH, "Programming Languages")
    if not os.path.isdir(pl_root): return
    for lang_name in sorted(os.listdir(pl_root)):
        lp = os.path.join(pl_root, lang_name)
        if not os.path.isdir(lp): continue
        problems = sorted(d for d in os.listdir(lp) if os.path.isdir(os.path.join(lp,d)))
        rows = "\n".join(f"| [{p}](./{p}/) |" for p in problems)
        with open(os.path.join(lp,"README.md"),"w") as f:
            f.write(f"# {lang_name} Solutions\n\n{len(problems)} problem(s).\n\n"
                    f"| Problem |\n|---------|\n{rows}\n")


# ============== MAIN README ==============
def generate_main_readme(tracker, user_data):
    problems = tracker.get("problems", {})
    total    = len(problems)
    info     = user_data.get("info", {})
    history  = user_data.get("rating_history", [])
    rb = {"≤800":0,"900-1200":0,"1300-1600":0,"1700-2000":0,"2100+":0}
    cc, lc, rows = {}, {}, []
    for key, p in sorted(problems.items(), key=lambda x: x[0]):
        r = p.get("rating",0) or 0
        if   r<=800:  rb["≤800"]+=1
        elif r<=1200: rb["900-1200"]+=1
        elif r<=1600: rb["1300-1600"]+=1
        elif r<=2000: rb["1700-2000"]+=1
        else:         rb["2100+"]+=1
        cat = p.get("category","Misc"); cc[cat]=cc.get(cat,0)+1
        for l in p.get("langs",[p.get("lang","")]):
            fn=LANG_FOLDER_MAP.get(l.lower(),l); lc[fn]=lc.get(fn,0)+1
        rows.append(
            f"| [{p.get('title',key)}]({CF_BASE}/contest/{p.get('contest_id','')}"
            f"/problem/{p.get('index','')}) "
            f"| {p.get('rating','?')} | {cat} "
            f"| {', '.join(f'`{l}`' for l in p.get('langs',[p.get('lang','')]))} "
            f"| {p.get('date','')} |"
        )
    recent = ""
    for r in list(reversed(history))[:5]:
        o=r.get("oldRating",0); n=r.get("newRating",0); d=n-o
        ds=datetime.fromtimestamp(r.get("ratingUpdateTimeSeconds",0),
                                  tz=timezone.utc).strftime("%Y-%m-%d")
        recent+=(f"| [{r.get('contestName','?')}]({CF_BASE}/contest/{r.get('contestId','')}) "
                 f"| {r.get('rank','?')} | {o}→{n} | {'🟢 +' if d>=0 else '🔴 '}{abs(d)} | {ds} |\n")
    with open(os.path.join(REPO_PATH,"README.md"),"w",encoding="utf-8") as f:
        f.write(f"""# ⚡ Codeforces — @{CF_HANDLE}

Auto-synced · {datetime.now(tz=timezone.utc).strftime("%Y-%m-%d %H:%M UTC")}
🔗 [{CF_BASE}/profile/{CF_HANDLE}]({CF_BASE}/profile/{CF_HANDLE})

## 🏆 Stats

| Rating | Peak | Rank | Contests | Solved |
|--------|------|------|----------|--------|
| **{info.get('rating','?')}** | **{info.get('maxRating','?')}** | {(info.get('rank') or '?').title()} | {len(history)} | {total} |

### 📈 Recent Contests ([full history](./Contests/))

| Contest | Rank | Rating | Δ | Date |
|---------|------|--------|---|------|
{recent}
## 📊 By Difficulty

| Range | Count |
|-------|-------|
{chr(10).join(f'| {b} | {n} |' for b,n in rb.items())}

## 🗂️ By Topic

| Category | Count |
|----------|-------|
{chr(10).join(f'| {c} | {n} |' for c,n in sorted(cc.items(),key=lambda x:-x[1]))}

## 💻 By Language

| Language | Count |
|----------|-------|
{chr(10).join(f'| [{l}](./Programming%20Languages/{l}/) | {n} |' for l,n in sorted(lc.items(),key=lambda x:-x[1]))}

## 📋 All Solutions

| Title | Rating | Category | Languages | Solved |
|-------|--------|----------|-----------|--------|
{chr(10).join(rows)}
""")
    print("  📄 README.md updated")


# ============== GIT PUSH ==============
def push_to_github():
    git_dir = os.path.join(REPO_PATH, ".git")
    if not os.path.isdir(git_dir):
        print("  ⚠ No git repo — run: git init && git remote add origin <url>"); return
    repo = Repo(REPO_PATH)
    repo.git.add(A=True)
    if not repo.is_dirty(index=True, working_tree=True, untracked_files=True):
        print("Nothing new to commit."); return
    repo.index.commit(f"🤖 CF sync [{datetime.now(tz=timezone.utc).strftime('%Y-%m-%d %H:%M')} UTC]")
    repo.remote(name="origin").push()
    print("🚀 Pushed to GitHub!")


# ============== MAIN ==============
def run():
    if not REPO_PATH:
        raise EnvironmentError("Set CF_REPO_PATH in .env file")
    if not CF_API_KEY or not CF_API_SECRET:
        print("⚠️ CF_API_KEY or CF_API_SECRET missing — trying unsigned API for metadata…")

    already_saved = load_already_saved_ids()
    failed_ids    = load_failed_ids()   # from previous run(s)

    tracker    = load_tracker()
    synced_ids = set(tracker["synced_ids"])
    counts     = tracker.setdefault("counts", {})

    # IDs to retry: previously failed + in tracker but .txt is missing
    retry_ids = failed_ids | {sid for sid in synced_ids if sid not in already_saved}
    if retry_ids:
        print(f"  🔁 {len(retry_ids)} submission(s) to retry (failed/incomplete from previous runs)\n")

    print(f"🔍 Fetching submissions for @{CF_HANDLE}…\n")
    submissions = fetch_submissions()
    print(f"\n📊 Fetching profile & rating…")
    user_data = fetch_user_info()
    print()

    new_count    = 0
    still_failed = set()

    for sub in reversed(submissions):
        sub_id = str(sub.get("id"))

        # Fully done — skip
        if sub_id in synced_ids and sub_id in already_saved:
            continue

        p = sub.get("problem", {})
        label = "🔁 Retrying" if sub_id in retry_ids else "⬇"
        print(f"  {label} {p.get('name','?')} ({sub.get('programmingLanguage','')})  [{sub_id}]")

        code = fetch_code(sub)

        if not code:
            still_failed.add(sub_id)
            print(f"  ⏭ Skipping {sub_id} (saved to .failed_ids.json — will retry next run)\n")
            continue

        prob_key  = f"{sub.get('contestId','0')}{p.get('index','A')}"
        count_key = f"{prob_key}::{sub.get('programmingLanguage','')}"
        attempt_num = counts.get(count_key, 0) + 1
        counts[count_key] = attempt_num

        lang_norm, lf, category = save_solution(sub, code, attempt_num)

        date_str = datetime.fromtimestamp(
            int(sub.get("creationTimeSeconds", time.time())), tz=timezone.utc
        ).strftime("%Y-%m-%d")

        existing = tracker["problems"].get(prob_key, {})
        langs    = existing.get("langs", [])
        lang     = sub.get("programmingLanguage", "")
        if lang not in langs:
            langs.append(lang)

        tracker["problems"][prob_key] = {
            "title": p.get("name","?"), "rating": p.get("rating",0),
            "category": category, "contest_id": str(sub.get("contestId","")),
            "index": p.get("index",""), "tags": p.get("tags",[]),
            "langs": langs, "lang": lang, "date": date_str,
        }
        if sub_id not in synced_ids:
            tracker["synced_ids"].append(sub_id)
            synced_ids.add(sub_id)

        still_failed.discard(sub_id)  # succeeded — remove from failures
        new_count += 1

    save_failed_ids(still_failed)
    if still_failed:
        print(f"\n⚠ {len(still_failed)} submission(s) could not be fetched — saved to .failed_ids.json")

    kill_browser()

    save_contest_stats(user_data, REPO_PATH)
    _gen_lang_indexes()
    generate_main_readme(tracker, user_data)
    save_tracker(tracker)
    push_to_github()
    print(f"\n✅ Done! {new_count} new submission(s) synced.")

if __name__ == "__main__":
    run()
