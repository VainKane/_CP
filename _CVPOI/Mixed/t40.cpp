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

int const N = 755;

int n;

int a[N][N];
int pre[N][N];

int dp[N][N];

int Get(int top, int bot, int left, int right)
{
    if (left > right || top > bot) return 0;
    return pre[bot][right] - pre[top - 1][right] - pre[bot][left - 1] + pre[top - 1][left - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(j, 2, n) FOR(i, 1, j - 1)
    {
        cin >> a[i][j];
        pre[i][j] += max(-a[i][j], 0);
    }

    FOR(i, 1, n) FOR(j, 1, n) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    memset(dp, 0x3f, sizeof dp);
    FOR(u, 1, n) dp[u][u] = 0;

    FORD(i, n, 1) FOR(j, i + 1, n) FOR(k, i, j)
        mini(dp[i][j], dp[i][k] + dp[k + 1][j] + max(a[i][k + 1], 0) + Get(i + 1, k, k + 1, j));

    cout << dp[1][n];

    return 0;
}