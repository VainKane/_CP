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

int const N = 509;

int a, b;
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    memset(dp, 0x3f, sizeof dp);
    FOR(i, 1, min(a, b)) dp[i][i] = 0;

    FOR(i, 1, a) FOR(j, 1, b)
    {
        FOR(k, 1, i - 1) mini(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        FOR(k, 1, j - 1) mini(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
    }

    cout << dp[a][b];

    return 0;
}