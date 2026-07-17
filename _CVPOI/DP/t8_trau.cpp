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
int cnt[N][2 * M];

int dp[N][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> n >> m;
    FOR(i, 1, s) FOR(j, 1, n)
    {
        int x; cin >> x;
        req[i][j] = 2 * x + 1;
    }

    FOR(j, 1, n)
    {
        FOR(i, 1, s) cnt[j][req[i][j]]++;
        FOR(i, 1, oo) cnt[j][i] += cnt[j][i - 1];
    }

    FOR(i, 1, n) FOR(j, 0, m) FOR(x, 0, j)
        maxi(dp[i][j], dp[i - 1][j - x] + i * cnt[i][x]);

    cout << dp[n][m];

    return 0;
}