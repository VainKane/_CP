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

int const N = 36;
int const MOD = 1e9 + 9;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, k, m;
int a[N][N];

int f[MK(22) + 5], g[MK(22) + 5];
int c[N][N];
int dp[N];

void Init()
{
    c[0][0] = 1;
    FOR(i, 1, n) FOR(j, 0, i)
    {
        c[i][j] = c[i - 1][j];
        if (j) c[i][j] += c[i - 1][j - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    REP(i, n) REP(j, m)
    {
        string s; cin >> s;
        for (auto &c : s) a[i][j] |= MK(c - 'a');
    }

    Init();

    REP(mask, MK(n)) g[mask] = 1;
    f[0] = MK(26) - 1;

    REP(j, m) FOR(mask, 1, MK(n) - 1)
    {
        int i = __builtin_ctz(mask);
        f[mask] = f[mask ^ MK(i)] & a[i][j];
        g[mask] = 1LL * g[mask] * __builtin_popcount(f[mask]) % MOD;
    }

    REP(mask, MK(n)) Add(dp[__builtin_popcount(mask)], g[mask]);
    FORD(i, n, 1) FOR(j, i + 1, n) dp[i] = (dp[i] - 1LL * c[j][i] * dp[j] + 1LL * MOD * MOD) % MOD;

    int res = 0;
    FOR(i, k, n) Add(res, dp[i]);
    cout << res;

    return 0;
}