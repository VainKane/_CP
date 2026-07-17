#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

int const N = 1e5 + 5;
int const M = 109;
int const MOD = 1e9 + 7;

int n, m;

int a[N];
int dp[N][M];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    if (a[1]) dp[1][a[1]] = 1;
    else FOR(i, 1, m) dp[1][i] = 1;

    FOR(i, 2, n)
    {
        int l = a[i] ? a[i] : 1;
        int r = a[i] ? a[i] : m;

        FOR(j, l, r)
        {
            Add(dp[i][j], dp[i - 1][j - 1]);
            Add(dp[i][j], dp[i - 1][j + 1]);
            Add(dp[i][j], dp[i - 1][j]);
        }
    }

    int res = 0;
    FOR(x, 1, m) Add(res, dp[n][x]);
    cout << res;

    return 0;
}