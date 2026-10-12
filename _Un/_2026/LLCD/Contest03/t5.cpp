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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2009;

int n, m;

int a[N], b[N];
int preA[N], preB[N];

ll dp[N][N];
ll f[N][N], g[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i], a[i]--;
    FOR(i, 1, m) cin >> b[i], b[i]--;

    FOR(i, 1, n) preA[i] = preA[i - 1] + a[i];
    FOR(i, 1, m) preB[i] = preB[i - 1] + b[i];

    memset(dp, 0x3f, sizeof dp);
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);

    // FOR(i, 1, max(m, n)) dp[0][i] = dp[i][0] = 0;
    FOR(j, 1, m) dp[1][j] = 1LL * a[1] * preB[j];
    FOR(i, 1, n) dp[i][1] = 1LL * preA[i] * b[1];

    FOR(i, 1, n) FOR(j, 1, m)
    {
        dp[i][j] = min({dp[i][j], f[i - 1][j] + 1LL * b[j] * preA[i], g[i][j - 1] + 1LL * a[i] * preB[j]});
        f[i][j] = min(f[i - 1][j], dp[i][j - 1] - 1LL * b[j] * preA[i]);
        g[i][j] = min(g[i][j - 1], dp[i - 1][j] - 1LL * a[i] * preB[j]);
    }

    cout << dp[n][m];
 
    return 0;
}