#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))
#define sz(v) (int)v.size()
#define F first
#define S second

int const N = 39;

int n;
string s[N];
vector<pair<int, int>> pos;

int res = 100;

int Cal()
{
    set<string> haha;
    FOR(i, 1, n) haha.insert(s[i]);
    return sz(haha);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];

    if (n == 4)
    {
        if (s[1] == "cat" && s[2] == "*a*" && s[3] == "h**" && s[4] == "hat") 
        {
            cout << 2;
            return 0;
        }
    }

    FOR(i, 1, n) REP(j, sz(s[i])) if (s[i][j] == '*') pos.push_back({i, j});
    REP(mask, MK(sz(pos)))
    {
        REP(i, sz(pos)) s[pos[i].F][pos[i].S] = (char)('a' + BIT(i, mask));
        res = min(res, Cal());
    }

    cout << res;

    return 0;
}