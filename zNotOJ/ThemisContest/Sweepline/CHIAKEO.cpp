#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "CHIAKEO"

int const N = 2e5 + 5;

int n, m;
vector<pair<int, int>> events;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m) 
    {
        int l, r;
        cin >> l >> r;
        
        if (l <= r) 
        {
            events.push_back({l, 1});
            events.push_back({r + 1, -1});
        }
        else
        {
            events.push_back({l, 1});
            events.push_back({1, 1});
            events.push_back({r + 1, -1});
        }
    }

    events.push_back({n + 1, 0});
    sort(all(events));

    pair<int, int> res;
    int cur = 0;

    FOR(i, 0, sz(events) - 2)
    {
        cur += events[i].S;
        if (cur > res.F) res = {cur, events[i + 1].F - events[i].F};
        else if (cur == res.F) res.S += events[i + 1].F - events[i].F;
    }

    cout << res.F << ' ' << res.S;

    return 0;
}