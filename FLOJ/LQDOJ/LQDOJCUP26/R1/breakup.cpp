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
#define name "breakup"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 8009;
int const MOD = 1e9 + 22071997;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int m, n, q;
bool mark[N][N];

int f[N][N], g[N][N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> q;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        int t, b, l, r;
        cin >> t >> b >> l >> r;
        FOR(x, t, b) FOR(y, l, r) mark[x][y] = true;
    }

    f[1][2] = g[2][1] = 1;
    FOR(i, 1, m) FOR(j, 1, n) if (!mark[i][j])
    {
        Add(f[i + 1][j], f[i][j]);
        Add(f[i][j + 1], f[i][j]);

        Add(g[i + 1][j], g[i][j]);
        Add(g[i][j + 1], g[i][j]);
    }

    dp[m][n] = 1;
    FORD(i, m, 1) FORD(j, n, 1) if (!mark[i][j])
    {
        Add(dp[i - 1][j], dp[i][j]);
        Add(dp[i][j - 1], dp[i][j]);
    }

    FOR(i, 1, m) FOR(j, 1, n) if (mark[i][j]) f[i][j] = g[i][j] = dp[i][j] = 0;

    int res = 1LL * f[m][n] * g[m][n] % MOD;
    FOR(i, 1, m) FOR(j, 1, n) if (!mark[i][j])
    {
        if (i == 1 && j == 1) continue;
        if (i == m && j == n) continue;
        cout << i << ' ' << j << ' ' << f[i - 1][j] * g[i][j - 1] << '\n';
        res = (res - 1LL * f[i - 1][j] * g[i][j - 1]) % MOD;
    }

    cout << (res + MOD) % MOD;

    return 0;
}