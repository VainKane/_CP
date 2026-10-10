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
#define name "mom"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 109;
int const MOD = 1e9 + 19972207;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;
int a[N];

int f[2][N][N * 500], g[2][N][N * 500];
int dp[N][N * 500];
int pre[N], suf[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);

    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
    FORD(i, n, 1) suf[i] = suf[i + 1] + a[i];

    int res = 0;
    bool cur = 1;
    FOR(i, 0, n + 1) f[cur][i][0] = g[cur][i][0] = 1;

    FOR(len, 1, n / 2)
    {
        cur ^= 1;
        FOR(i, 1, n)
        {
            FOR(x, 0, pre[i]) f[cur][i][x] = 0;
            FOR(x, 0, suf[i]) g[cur][i][x] = 0;
        }

        FORD(i, n - len - 1, len) FOR(x, 0, pre[i - 1]) Add(f[cur][i][x + a[i]], f[cur ^ 1][i - 1][x]);
        FOR(i, len, n - len - 1) FOR(x, 1, pre[i]) Add(f[cur][i][x], f[cur][i - 1][x]);

        FOR(i, len + 1, n - len + 1) FOR(x, 0, suf[i + 1]) Add(g[cur][i][x + a[i]], g[cur ^ 1][i + 1][x]);
        FORD(i, n - len + 1, len + 1) FOR(x, 1, suf[i])
        {
            Add(g[cur][i][x], g[cur][i + 1][x]);
            dp[i][x] = (dp[i][x - 1] + g[cur][i][x]) % MOD;
        }

        int k = 2 * len;
        FOR(i, len + 1, n - len) FOR(x, 1, pre[i - 1]) if (f[cur][i - 1][x])
            res = (res + 1LL * f[cur][i - 1][x] * dp[i + 1][min(suf[i + 1], a[i] * k - x - 1)]) % MOD;
    }

    cout << res;

    return 0;
}