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

int n, m, b, MOD;
int a[N];

int dp[2][N][N];
int cur = 1, pre = 0;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> b >> MOD;
    FOR(i, 1, n) cin >> a[i];

    dp[cur][0][0] = 1;

    FOR(i, 1, n)
    {
        swap(cur, pre);
        memset(dp[cur], 0, sizeof dp[cur]);

        FOR(j, 0, m) FOR(s, 0, b)
        {
            dp[cur][j][s] = dp[pre][j][s];
            if (j && s >= a[i]) Add(dp[cur][j][s], dp[cur][j - 1][s - a[i]]);
        }
    }

    int res = 0;
    FOR(s, 0, b) Add(res, dp[cur][m][s]);
    cout << res;

    return 0;
}