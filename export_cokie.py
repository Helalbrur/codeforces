import browser_cookie3
import json

cookies = browser_cookie3.chrome(domain_name="codeforces.com")
cookie_list = [{"name": c.name, "value": c.value} for c in cookies]
with open("cf_cookies.json", "w") as f:
    json.dump(cookie_list, f, indent=2)
print("Cookies saved to cf_cookies.json")