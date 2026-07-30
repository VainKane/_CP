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

int const N = 109;

int m, n;
int a[N][N];

int dp[N][N][N];
pair<char, char> trace[N][N][N];

int d[256];
string mv = "LDR";

char res1[N], res2[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    d['L'] = -1, d['R'] = 1;

    FORD(i, m + 1, 1) FOR(x, 1, n) FOR(y, 1, n) for (auto &c1 : mv) for (auto &c2 : mv)
    {
        int u = x - d[c1];
        int v = y - d[c2];

        if (u < 1 || v < 1 || u > n || v > n) continue;
        if (maxi(dp[i - 1][u][v], dp[i][x][y] + a[i - 1][u] + a[i - 1][v] * (u != v))) trace[i - 1][u][v] = {c1, c2};
    }

    int x = 0, y = 0;
    FOR(u, 1, n) FOR(v, 1, n) if (dp[1][u][v] > dp[1][x][y]) x = u, y = v;

    cout << dp[1][x][y] << '\n' << x << ' ' << y << '\n';

    FOR(i, 1, m - 1)
    {
        char c1 = trace[i][x][y].F;
        char c2 = trace[i][x][y].S;

        res1[i] = c1, res2[i] = c2;
        x += d[c1], y += d[c2];
    }

    FOR(i, 1, m - 1) cout << res1[i];
    cout << '\n';
    FOR(i, 1, m - 1) cout << res2[i];

    return 0;
}