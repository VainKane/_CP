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
int const OS = 2e6 + 5;

int n, q;
int a[N];

long long dp[N][N];
short int f[N][N];

int cnt[2 * OS + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    FOR(l, 2, n - 1)
    {
        FOR(r, l, n - 1)
        {
            cnt[a[r] + OS]++;
            f[l - 1][r + 1] = cnt[-a[l - 1] - a[r + 1] + OS];
        }

        FOR(i, l, n - 1) cnt[a[i] + OS] = 0;
    }

    FORD(l, n, 1) FOR(r, l + 2, n)
        dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1] + f[l][r];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }

    return 0;
}
