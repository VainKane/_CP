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
int const MOD = 1e9 + 7;

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

int n, mi = N, ma = 0;
int cnt[N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        mini(mi, x), maxi(ma, x);
        cnt[x]++;
    }

    FOR(i, mi, ma) cnt[i] += cnt[i - 1];

    FORD(x, mi, 1)
    {
        dp[x] = 1;
        FOR(i, 1, ma / x) dp[x] = 1LL * dp[x] * PowMod(i, cnt[min(ma, (i + 1) * x - 1)] - cnt[i * x - 1]) % MOD;
        for (int i = 2 * x; i <= ma; i += x) Sub(dp[x], dp[i]);
    }

    cout << dp[1];

    return 0;
}