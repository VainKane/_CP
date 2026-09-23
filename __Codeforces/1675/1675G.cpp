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

int const N = 255;
int const OS = 251;

int n, m;
int a[N];

int dp[2][2 * N][2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    bool cur = 1;
    REP(i, n)
    {
        memset(dp[cur ^ 1], 0x3f, sizeof dp[cur ^ 1]);
        FOR(j, -m, m) FOR(x, -j, m) if (j + x >= a[i + 1] - x) FOR(k, j + x, m)
            mini(dp[cur ^ 1][a[i + 1] - x + OS][j + x + OS], dp[cur][j + OS][k + OS] + abs(x));

        // FORD(j, m - 1, -m) FORD(x, m, j) mini(dp[cur][j + OS][x + OS], dp[cur][j + OS][x + 1 + OS]);
        cur ^= 1;
        FOR(j, -m, m) FOR(x, j, m) cout << i + 1 << ' ' << j << ' ' << x << ": " <<  dp[cur ^ 1][j + OS][x + OS] << '\n';
    }

    int res = m;
    FOR(j, 0, m) FOR(x, j, m) mini(res, dp[cur][j + OS][x + OS]);
    cout << res;

    return 0;
}