import requests
import re

def check_codeforces_problem(url: str):
    # Extract contest ID and problem index
    match = re.search(r'/contest/(\d+)/problem/([A-Za-z0-9]+)', url)
    if not match:
        match = re.search(r'/problemset/problem/(\d+)/([A-Za-z0-9]+)', url)

    if not match:
        print("❌ Invalid Codeforces problem URL.")
        return

    contest_id, index = match.groups()

    print("🔍 Fetching problem info...")

    try:
        # Fetch all problems metadata
        response = requests.get("https://codeforces.com/api/problemset.problems")
        data = response.json()

        if data["status"] != "OK":
            print("❌ Failed to fetch problems list.")
            return

        problems = data["result"]["problems"]

        # Find your problem
        problem = next(
            (p for p in problems if str(p.get("contestId")) == contest_id and p.get("index") == index),
            None
        )

        if not problem:
            print("❌ Problem not found in Codeforces database.")
            return

        name = problem.get("name", "Unknown")
        tags = problem.get("tags", [])
        rating = problem.get("rating", None)

        bannedTags = ("constructive algorithms", "interactive")
        minRating = 1400
        maxRating = 2500

        print(f"\n📘 Problem: {name}")
        # print(f"🏷️ Tags: {', '.join(tags) if tags else 'No tags available'}")
        # print(f"X⭐ Rating: {rating if rating else 'Unknown'}")

        for tag in tags:
            if bannedTags.count(tag): 
                print("❌ Tag found:", tag); 

        if rating < minRating:
            print("❌ Rating <", minRating)
        elif rating > maxRating:
            print("❌ Rating >", maxRating)

        print("✅ Checking completed")

    except Exception as e:
        print(f"⚠️ Error: {e}")


if __name__ == "__main__":
    url = input("Enter Codeforces problem URL: ").strip()
    check_codeforces_problem(url)
