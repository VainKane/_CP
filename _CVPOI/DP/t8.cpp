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

int const N = 109;
int const M = 2e4 + 5;
int const oo = 4e4 + 1;

int s, n, m;

int req[N][N];
int dp[N][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> n >> m;
    FOR(j, 1, s) FOR(i, 1, n)
    {
        int x; cin >> x;
        req[i][j] = 2 * x + 1;
    }

    FOR(i, 1, n) sort(req[i] + 1, req[i] + s + 1);

    FOR(i, 1, n) FOR(j, 1, s) FOR(k, 0, m)
    {
        maxi(dp[i][k], dp[i - 1][k]);
        if (k >= req[i][j]) maxi(dp[i][k], dp[i - 1][k - req[i][j]] + i * j);
    }

    cout << dp[n][m];

    return 0;
}