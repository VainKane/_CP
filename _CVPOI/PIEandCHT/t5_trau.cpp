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

int const N = 2e5 + 5;
int const oo = 2e5;
int const MOD = 1e9 + 7;

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int n;

int p[N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> p[i];

    FORD(x, oo, 1)
    {
        dp[x] = 1;
        FOR(i, 1, n) dp[x] = 1LL * dp[x] * (p[i] / x) % MOD;
        for (int i = 2 * x; i <= oo; i += x) Sub(dp[x], dp[i]);
    }

    cout << dp[1];

    return 0;
}