#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 309;
int const oo = 1e9;

int n, m;

char s[N], t[N];
vector<int> pos[256];

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    FOR(i, 1, n) cin >> s[i], pos[s[i]].push_back(i);
    FOR(i, 1, m) cin >> t[i];

    memset(dp, 0x3f, sizeof dp);
    for (auto &i : pos[t[1]]) dp[i][1] = 0;

    FOR(j, 1, m - 1) for (auto &i : pos[t[j]])
    {
        for (auto &p : pos[t[j]]) mini(dp[i][j], dp[p][j] + abs(i - p));
        if (s[i - 1] == t[j + 1]) mini(dp[i - 1][j + 1], dp[i][j] + 1);
        if (s[i + 1] == t[j + 1]) mini(dp[i + 1][j + 1], dp[i][j] + 1);
    }

    int res = oo;
    for (auto &i : pos[t[m]]) mini(res, dp[i][m]);
    if (res == oo) res = -1;

    cout << res;

    return 0;
}