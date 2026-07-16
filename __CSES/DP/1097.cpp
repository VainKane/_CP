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

int const N = 5009;

int n;
int a[N];

long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    memset(dp, -0x3f, sizeof dp);
    FOR(i, 1, n) dp[i][i] = (n & 1) ? a[i] : 0;

    FORD(i, n, 1) FOR(j, i + 1, n)
    {
        if (((j - i + 1) & 1) == (n & 1)) dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
        else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
    }

    cout << dp[1][n];
    // cout << dp[1][2];

    return 0;
}