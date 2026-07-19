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

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int t, k;

int dp[N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t >> k;

    dp[0] = 1;

    FOR(i, 1, 1e5)
    {
        dp[i] = dp[i - 1];
        if (i - k >= 0) Add(dp[i], dp[i - k]);
    }

    FOR(i, 1, 1e5) Add(dp[i], dp[i - 1]);

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << (dp[r] - dp[l - 1] + MOD) % MOD << '\n';
    }

    return 0;
}