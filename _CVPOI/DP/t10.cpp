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

int const N = 2e4 + 5;
int const M = 109;

int m, n, k;
int a[N][M];
pair<int, int> b[N];

bool cur = 0;
int dp[2][M * M];
bool f[M][M * M];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.F != b.F) return a.F > b.F;
    return a.S < b.S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    FOR(i, 1, m)
    {
        b[i].S = i;
        FOR(j, 1, n) cin >> a[i][j], b[i].F += a[i][j];
    }

    sort(b + 1, b + m + 1, cmp);

    FOR(i, 1, m)
    {
        cur ^= 1;
        memset(dp[cur], 0x3f, (n * k + 2) * sizeof(int));

        f[n][b[i].F] = 1;
        FOR(j, 1, n) FOR(t, 0, n) FOR(x, b[i + 1].F, b[i].F) // this shit shouldn't be tle
            f[t][x] |= f[t + 1][x + a[b[i].S][j]];

        FOR(t, 0, n) FOR(x, b[i + 1].F, b[i].F) if (f[t][x])
        {
            int y = x + k * (n - t) + (b[i].S < b[i - 1].S);
            mini(dp[cur][x], dp[cur ^ 1][y] + t);
            f[t][x] = 0;
        } 

        FORD(x, b[i].F, b[i + 1].F) mini(dp[cur][x], dp[cur][x + 1]);
    }

    cout << *min_element(dp[cur], dp[cur] + k * n + 1);

    return 0;
}