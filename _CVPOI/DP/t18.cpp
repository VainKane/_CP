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
int const K = 12;
long long const oo = 1e18 + 67;

int n, k;
long long a[N][K];
int b[N];

long long dp[N][K][K];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i][0];
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n) FOR(j, 1, k) a[i][j] = 1LL * a[i][j - 1] * b[i];

    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0] = 0;

    REP(i, n) FOR(u, 0, k) FOR(v, 0, u) FOR(c1, 0, k - u) FOR(c2, 0, u - v + c1)
    {
        maxi(dp[i + 1][u + c1][v + c2], a[i + 1][u + c1 - v - c2]);
        maxi(dp[i + 1][u + c1][v + c2], dp[i][u][v] + a[i + 1][u + c1 - v - c2]);
    }

    long long res = -oo;
    FOR(i, 1, n) FOR(u, 0, k) FOR(v, 0, u) maxi(res, dp[i][u][v]);
    cout << res;

    return 0;
}