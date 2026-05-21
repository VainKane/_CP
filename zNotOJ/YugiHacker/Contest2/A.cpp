#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "lock"

int m, n;
vector<pair<int, int>> events;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b + 1, -1});
    }

    events.push_back({1, 0});
    events.push_back({m + 1, 0});
    sort(all(events));

    int res = 0;
    int cur = 0;

    FOR(i, 0, sz(events) - 2)
    {
        cur = (cur + events[i].S + 3) % 3;
        if (!cur) res += events[i + 1].F - events[i].F;
    }

    cout << res;

    return 0;
}