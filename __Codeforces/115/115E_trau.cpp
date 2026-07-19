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

int const N = 5009;

int n, m;

int a[N];
long long val[N][N];

long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    while (m--)
    {
        int l, r, p;
        cin >> l >> r >> p;

        val[l][r] += p;
    }

    FOR(l, 1, n) FOR(r, l + 1, n) val[l][r] += val[l][r - 1];

    FOR(i, 1, n)
    {
        dp[i] = dp[i - 1];

        long long cost = 0, money = 0;
        FORD(j, i, 1)
        {
            cost += a[j];
            money += val[j][i];

            maxi(dp[i], dp[j - 1] + money - cost);
        }
    }

    cout << dp[n];

    return 0;
}