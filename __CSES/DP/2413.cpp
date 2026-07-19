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

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

int dp[N][2];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp[1][1] = dp[1][0] = 1;
    FOR(i, 2, 1e6)
    {
        dp[i][1] = (4ll * dp[i - 1][1] + dp[i - 1][0]) % MOD;
        dp[i][0] = (2ll * dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }

    return 0;
}