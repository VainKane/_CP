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

int const N = 301;

int m, n;
char a[N][N];

pair<int, string> dp[2][N][N];
bool cur = 0;

void Optimize(int x, int y, int k, int u, int v)
{
    if (v < 1 || v > n) return;
    if (a[u][v] == '*') return;

    int delta = 0, val = 0;
    if (a[x][y] == '(') delta = -1, val = 1;
    if (a[x][y] == ')') delta = 1, val = 1;

    if (k + delta < 0 || dp[cur ^ 1][v][k + delta].F == -1) return;
    int len = dp[cur ^ 1][v][k + delta].F + val;

    string haha = dp[cur ^ 1][v][k + delta].S;
    if (val) haha += a[x][y];

    if (maxi(dp[cur][y][k].F, len)) dp[cur][y][k].S = haha;
    else if (dp[cur][y][k].F == len) dp[cur][y][k].S = min(dp[cur][y][k].S, haha);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(j, 1, n) FOR(k, 0, m) REP(cur, 2) dp[cur][j][k].F = -1;
    FOR(j, 1, n) if (a[m][j] == 'M') dp[cur ^ 1][j][0].F = 0;

    string res;
    int len = 0;

    FORD(i, m - 1, 1)
    {
        FOR(j, 1, n) FOR(k, 0, m)
        {
            Optimize(i, j, k, i + 1, j);
            Optimize(i, j, k, i + 1, j - 1);
            Optimize(i, j, k, i + 1, j + 1);
        }

        FOR(j, 1, n) if (a[i][j] == '*' || i == 1)
        {
            if (maxi(len, dp[cur][j][0].F)) res = dp[cur][j][0].S;
            else if (len == dp[cur][j][0].F) res = min(res, dp[cur][j][0].S);
        }
        
        cur ^= 1;
        FOR(j, 1, n) FOR(k, 0, m) dp[cur][j][k].F = -1;
    }

    cout << len << '\n' << res;

    return 0;
}