"""
Codeforces Auto-Sync
Uses undetected-chromedriver to bypass Cloudflare bot detection.
Install deps:
    pip install undetected-chromedriver selenium browser-cookie3 \
                requests python-dotenv gitpython beautifulsoup4
"""
import re, os, json, time, random, html
from bs4 import BeautifulSoup
from dotenv import load_dotenv
from datetime import datetime, timezone
from git import Repo
import requests

# ── undetected-chromedriver bypasses Cloudflare ──────────────────────
import undetected_chromedriver as uc
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support   import expected_conditions as EC

try:
    import browser_cookie3 as bc3
    _HAS_BC3 = True
except ImportError:
    _HAS_BC3 = False

# ================= CONFIG =================
_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
load_dotenv(os.path.join(_SCRIPT_DIR, ".env"))

CF_HANDLE  = os.getenv("CF_HANDLE", "Helaluddin_brur")
REPO_PATH  = os.getenv("CF_REPO_PATH")
CF_API_URL = "https://codeforces.com/api"
CF_BASE    = "https://codeforces.com"
HEADERS_API = {"user-agent": "Mozilla/5.0", "accept": "application/json"}

# ============================================================
#  BROWSER SESSION  (undetected Chrome + live cookies)
# ============================================================

def _get_cf_cookies() -> list:
    """Read CF session cookies from any installed browser."""
    if not _HAS_BC3:
        return []
    for name, loader in [
        ("Chrome",   lambda: bc3.chrome(domain_name="codeforces.com")),
        ("Chromium", lambda: bc3.chromium(domain_name="codeforces.com")),
        ("Firefox",  lambda: bc3.firefox(domain_name="codeforces.com")),
        ("Brave",    lambda: bc3.brave(domain_name="codeforces.com")),
        ("Edge",     lambda: bc3.edge(domain_name="codeforces.com")),
    ]:
        try:
            jar = list(loader())
            cf_cookies = [
                {"name": c.name, "value": c.value,
                 "domain": ".codeforces.com", "path": "/", "secure": c.secure}
                for c in jar
            ]
            if any(c["name"] == "JSESSIONID" for c in cf_cookies):
                print(f"  🍪 CF session found in {name} ({len(cf_cookies)} cookies)")
                return cf_cookies
        except Exception:
            continue
    print("  ⚠ No CF session found in any browser — will try without cookies")
    return []

def make_driver() -> uc.Chrome:
    """
    Start an undetected Chrome instance.
    undetected-chromedriver patches the binary so Cloudflare
    cannot distinguish it from a real human browser.
    """
    opts = uc.ChromeOptions()
    opts.add_argument("--no-sandbox")
    opts.add_argument("--disable-dev-shm-usage")
    opts.add_argument("--window-size=1280,900")
    opts.add_argument("--disable-blink-features=AutomationControlled")
    # headless=True uses the new headless mode which is much harder to detect
    # Auto-detect installed Chrome version to avoid driver/browser mismatch
    chrome_version = None
    try:
        import subprocess
        out = subprocess.check_output(
            ["google-chrome", "--version"], stderr=subprocess.DEVNULL
        ).decode().strip()
        chrome_version = int(out.split()[-1].split(".")[0])
        print(f"  🟡 Detected Chrome {chrome_version}")
    except Exception:
        try:
            import subprocess
            out = subprocess.check_output(
                ["chromium-browser", "--version"], stderr=subprocess.DEVNULL
            ).decode().strip()
            chrome_version = int(out.split()[-1].split(".")[0])
            print(f"  🟡 Detected Chromium {chrome_version}")
        except Exception:
            pass

    driver = uc.Chrome(
        options=opts,
        headless=True,
        use_subprocess=True,
        version_main=chrome_version,   # pin driver to match installed Chrome
    )
    driver.set_page_load_timeout(40)
    print("  🤖 undetected-chromedriver started (Cloudflare bypass active)")

    # Inject session cookies so CF sees us as logged in
    driver.get(CF_BASE)
    time.sleep(2)
    for cookie in _get_cf_cookies():
        try:
            driver.add_cookie(cookie)
        except Exception:
            pass
    driver.refresh()
    time.sleep(2)

    title = driver.title
    print(f"  🌐 Page: {title[:70]}")
    if "Codeforces" in title:
        if "Enter" not in title and "login" not in title.lower():
            print("  ✅ Logged in successfully")
        else:
            print("  ⚠ Not logged in — open codeforces.com in Chrome and sign in")
    return driver

DRIVER: uc.Chrome | None = None

def get_driver() -> uc.Chrome:
    global DRIVER
    if DRIVER is None:
        DRIVER = make_driver()
    return DRIVER

def quit_driver():
    global DRIVER
    if DRIVER is not None:
        try:
            DRIVER.quit()
        except Exception:
            pass
        DRIVER = None

GYM_THRESHOLD = 100000

# ============== MAPS ==============
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

# ============== FETCH SUBMISSIONS ==============
def fetch_submissions():
    print(f"  📡 Fetching submissions for @{CF_HANDLE}…")
    r = requests.get(f"{CF_API_URL}/user.status", headers=HEADERS_API,
                     params={"handle": CF_HANDLE, "from": 1, "count": 10000}, timeout=30)
    r.raise_for_status()
    data = r.json()
    if data.get("status") != "OK":
        raise RuntimeError(f"CF API error: {data.get('comment')}")
    all_s    = data["result"]
    accepted = [s for s in all_s if s.get("verdict") == "OK"]
    print(f"  Total: {len(all_s)}  |  ✅ Accepted: {len(accepted)}  "
          f"|  ⏭ Skipped: {len(all_s)-len(accepted)}")
    return accepted

# ============== FETCH USER INFO ==============
def fetch_user_info():
    result = {"info": {}, "rating_history": []}
    try:
        r = requests.get(f"{CF_API_URL}/user.info", headers=HEADERS_API,
                         params={"handles": CF_HANDLE}, timeout=15)
        if r.ok and r.json().get("status") == "OK":
            result["info"] = r.json()["result"][0]
            print(f"  👤 Rating: {result['info'].get('rating','N/A')}  "
                  f"Rank: {result['info'].get('rank','N/A')}")
    except Exception as e:
        print(f"  ⚠ {e}")
    try:
        r = requests.get(f"{CF_API_URL}/user.rating", headers=HEADERS_API,
                         params={"handle": CF_HANDLE}, timeout=15)
        if r.ok and r.json().get("status") == "OK":
            result["rating_history"] = r.json()["result"]
            print(f"  📈 Contests: {len(result['rating_history'])}")
    except Exception as e:
        print(f"  ⚠ {e}")
    return result

# ============== SAVE CONTEST STATS ==============
def save_contest_stats(user_data, repo_path):
    info    = user_data.get("info", {})
    history = user_data.get("rating_history", [])
    if not info and not history:
        return
    folder = os.path.join(repo_path, "Contests")
    os.makedirs(folder, exist_ok=True)
    rows = ""
    peak = 0
    for i, r in enumerate(history):
        o = r.get("oldRating", 0); n = r.get("newRating", 0); d = n - o
        ds = datetime.fromtimestamp(r.get("ratingUpdateTimeSeconds", 0),
                                    tz=timezone.utc).strftime("%Y-%m-%d")
        peak = max(peak, n)
        rows += (f"| {i+1} | [{r.get('contestName','?')}]"
                 f"({CF_BASE}/contest/{r.get('contestId','')}) "
                 f"| {r.get('rank','—')} | {o} | {n} "
                 f"| {'🟢 +' if d>=0 else '🔴 '}{abs(d)} | {ds} |\n")
    with open(os.path.join(folder, "README.md"), "w", encoding="utf-8") as f:
        f.write(f"""# ⚡ Contest History — @{CF_HANDLE}

🔗 [{CF_BASE}/profile/{CF_HANDLE}]({CF_BASE}/profile/{CF_HANDLE})

## 🏆 Standing

| Field | Value |
|-------|-------|
| Current Rating | **{info.get('rating','Unrated')}** |
| Peak Rating | **{info.get('maxRating', peak)}** |
| Current Rank | {info.get('rank','Unrated')} |
| Peak Rank | {info.get('maxRank','Unrated')} |
| Contests | {len(history)} |

## 📈 Rating History

| # | Contest | Rank | Old | New | Change | Date |
|---|---------|------|-----|-----|--------|------|
{rows}
""")
    for r in history:
        cid = r.get("contestId","")
        safe = re.sub(r'[^\w\s-]', '', r.get("contestName","?")).replace(" ","_")[:60]
        o = r.get("oldRating",0); n = r.get("newRating",0); d = n-o
        ds = datetime.fromtimestamp(r.get("ratingUpdateTimeSeconds",0),
                                    tz=timezone.utc).strftime("%Y-%m-%d")
        with open(os.path.join(folder, f"{cid}_{safe}.md"), "w", encoding="utf-8") as f:
            f.write(f"# {r.get('contestName','?')}\n\n"
                    f"| Field | Value |\n|-------|-------|\n"
                    f"| Date | {ds} |\n| Rank | {r.get('rank','—')} |\n"
                    f"| Old Rating | {o} |\n| New Rating | {n} |\n"
                    f"| Change | {'+'if d>=0 else ''}{d} |\n"
                    f"| Link | [Contest]({CF_BASE}/contest/{cid}) |\n"
                    f"| Standing | [My Result]({CF_BASE}/contest/{cid}"
                    f"/standings/participant/handle/{CF_HANDLE}) |\n")
    print(f"  📄 Contests/ saved ({len(history)} contests)")

# ============== FETCH CODE ==============
def submission_url(sub):
    cid = sub.get("contestId"); sid = sub.get("id")
    if cid is None:
        return f"{CF_BASE}/problemset/submission/{CF_HANDLE}/{sid}"
    if cid >= GYM_THRESHOLD:
        return f"{CF_BASE}/gym/{cid}/submission/{sid}"
    return f"{CF_BASE}/contest/{cid}/submission/{sid}"

def fetch_code(sub) -> str | None:
    url = submission_url(sub)
    sid = sub.get("id")
    time.sleep(random.uniform(1.0, 2.0))
    try:
        driver = get_driver()
        driver.get(url)
        time.sleep(2)   # wait for JS + Cloudflare challenge to resolve

        # Selectors matching CF submission page layout (pre.prettyprint confirmed in screenshot)
        for by, sel in [
            (By.ID,           "program-source-text"),
            (By.CSS_SELECTOR, "pre.prettyprint"),
            (By.CSS_SELECTOR, "pre.program-source"),
            (By.CSS_SELECTOR, "pre.linenums"),
            (By.CSS_SELECTOR, "div.roundbox.titled pre"),
            (By.CSS_SELECTOR, ".source-code pre"),
        ]:
            try:
                el = WebDriverWait(driver, 8).until(
                    EC.presence_of_element_located((by, sel))
                )
                t = el.text.strip()
                if t and len(t) > 5:
                    return t
            except Exception:
                continue

        # Fallback: any <pre> with enough content
        for pre in driver.find_elements(By.TAG_NAME, "pre"):
            t = pre.text.strip()
            if len(t) > 20:
                return t

        # BeautifulSoup on fully rendered DOM
        soup = BeautifulSoup(driver.page_source, "html.parser")
        for tag in soup.find_all("pre"):
            t = tag.get_text().strip()
            if len(t) > 20:
                return html.unescape(t)

        print(f"    ✗ No code found for {sid}")
        return None
    except Exception as e:
        print(f"    ⚠ Error {sid}: {e}")
        return None

# ============== BUILD & SAVE ==============
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
        (os.path.join(REPO_PATH, "Programming Languages", lf, folder_name),  False),
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
        ds=datetime.fromtimestamp(r.get("ratingUpdateTimeSeconds",0),tz=timezone.utc).strftime("%Y-%m-%d")
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
        raise EnvironmentError("Set CF_REPO_PATH in your .env file.")
    tracker    = load_tracker()
    synced_ids = set(tracker["synced_ids"])
    counts     = tracker.setdefault("counts", {})
    new_count  = 0

    print(f"🔍 Fetching submissions for @{CF_HANDLE}…\n")
    submissions = fetch_submissions()
    print(f"\n📊 Fetching profile & rating…")
    user_data = fetch_user_info()
    print()

    for sub in reversed(submissions):
        sub_id = str(sub.get("id"))
        if sub_id in synced_ids:
            continue
        p   = sub.get("problem", {})
        print(f"  ⬇ {p.get('name','?')} ({sub.get('programmingLanguage','')})  [{sub_id}]")
        code = fetch_code(sub)
        if not code:
            continue
        prob_key          = f"{sub.get('contestId','0')}{p.get('index','A')}"
        count_key         = f"{prob_key}::{sub.get('programmingLanguage','')}"
        attempt_num       = counts.get(count_key, 0) + 1
        counts[count_key] = attempt_num
        lang_norm, lf, category = save_solution(sub, code, attempt_num)
        date_str = datetime.fromtimestamp(int(sub.get("creationTimeSeconds", time.time())),
                                          tz=timezone.utc).strftime("%Y-%m-%d")
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
        synced_ids.add(sub_id)
        tracker["synced_ids"].append(sub_id)
        new_count += 1

    save_contest_stats(user_data, REPO_PATH)
    _gen_lang_indexes()
    generate_main_readme(tracker, user_data)
    save_tracker(tracker)
    push_to_github()
    quit_driver()
    print(f"\n✅ Done! {new_count} new submission(s) synced.")

if __name__ == "__main__":
    run()
