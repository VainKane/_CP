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
int const MOD = 9999973;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int m, n;

int dp[2][N][N];
bool cur = 1;

int F(int c0, int c1)
{
    int c2 = n - c0 - c1;
    if (min({c0, c1, c2}) < 0 || max({c0, c1, c2}) > n) return 0;
    return dp[cur ^ 1][c0][c1];
}

int C2(int x) { return 1LL * x * (x - 1) / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    dp[cur][n][0] = 1;

    REP(haha, m)
    {
        cur ^= 1;
        memset(dp[cur], 0, sizeof dp[cur]);

        FOR(c0, 0, n) FOR(c1, 0, n - c0)
        {
            int &x = dp[cur][c0][c1];

            x = dp[cur ^ 1][c0][c1];
            x = (x + F(c0 + 1, c1 - 1) * (c0 + 1) + F(c0, c1 + 1) * (c1 + 1)) % MOD;
            x = (x + 1LL * F(c0 + 2, c1 - 2) * C2(c0 + 2)
                   + 1LL * F(c0, c1 + 2) * C2(c1 + 2)
                   + 1LL * F(c0 + 1, c1) * (c0 + 1) * c1) % MOD;
        }
    }

    int res = 0;
    FOR(c0, 0, n) FOR(c1, 0, n - c0) Add(res, dp[cur][c0][c1]);
    cout << res;

    return 0;
}