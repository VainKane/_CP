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

int const N = 5009;

int n, t, s;
int a[N], p[N];

long long dp[N][N];
bool trace[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t >> s;

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> p[i];

    FOR(i, 1, n) FOR(j, 1, t)
    {
        dp[i][j] = dp[i - 1][j];
        if (a[i] <= j) trace[i][j] = maxi(dp[i][j], dp[i - 1][j - a[i]] + 1LL * p[i] * (s - j));
    }

    vector<int> path;
    int u = 0;
    int v = 0;

    long long res = 0;
    FOR(i, 1, n) FOR(j, 1, t) if (maxi(res, dp[i][j])) u = i, v = j;

    while (u)
    {
        if (trace[u][v])
        {
            path.push_back(u);
            v -= a[u];
        }
        u--;
    }

    reverse(all(path));

    cout << sz(path) << ' ' << res << '\n';
    for (auto &id : path) cout << id << ' ';

    return 0;
}
