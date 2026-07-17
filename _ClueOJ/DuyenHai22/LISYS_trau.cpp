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
#define name "LISYS"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;

int a[N];
int dp[N][2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    dp[0][0] = 1;
    FOR(i, 1, n) FOR(j, 1, (n - 1) << 1)
    {
        if (a[i] != -1)
        {
            if (j >= a[i]) dp[i][j] = dp[i - 1][j - a[i]];
        }
        else FOR(k, 1, min(n - 1, j)) Add(dp[i][j], dp[i - 1][j - k]);
    }

    cout << dp[n][(n - 1) << 1];

    return 0;
}