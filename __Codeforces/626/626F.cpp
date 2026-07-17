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

int const N = 209;
int const MOD = 1e9 + 7;

int n, k;

int a[N];
int dp[N][N][1009];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    dp[0][0][0] = 1;

    REP(i, n) FOR(j, 0, i) FOR(s, 0, k)
    {
        int nxtS = s + j * (a[i + 1] - a[i]);
        int tmp = 1ll * j * dp[i][j][s] % MOD;

        if (nxtS > k) continue;

        Add(dp[i + 1][j][nxtS], tmp);
        if (j) Add(dp[i + 1][j - 1][nxtS], tmp);
        Add(dp[i + 1][j + 1][nxtS], dp[i][j][s]);
        Add(dp[i + 1][j][nxtS], dp[i][j][s]);
    }

    int res = 0;
    FOR(s, 0, k) Add(res, dp[n][0][s]);
    cout << res;

    return 0;
}