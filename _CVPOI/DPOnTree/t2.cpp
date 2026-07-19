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

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];
pair<int, int> dp[N][2];

void Add(pair<int, int> &x, pair<int, int> y1, pair<int, int> y2)
{
    pair<int, int> y = y1.F >= y2.F ? y1 : y2;
    if (y1.F == y2.F) y.S += y2.S;

    x.F += y.F;
    x.S = 1LL * x.S * y.S % MOD;
}

void DFS(int u, int p)
{
    dp[u][0].S = dp[u][1].S = dp[u][1].F = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        Add(dp[u][1], dp[v][0], make_pair(dp[v][1].F - 1, dp[v][1].S));
        Add(dp[u][0], dp[v][0], dp[v][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    pair<int, int> res = {0, 1};
    Add(res, dp[1][0], dp[1][1]);

    cout << res.F << ' ' << res.S;

    return 0;
}