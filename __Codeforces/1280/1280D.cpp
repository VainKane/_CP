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

int const N = 3009;
long long const oo = 1e13;

int n, m;   

int a[N];
vector<int> adj[N];

pair<int, long long> dp[N][N];
pair<int, long long> f[2][N];
int sz[N];

pair<int, long long> Add(pair<int, long long> a, pair<int, long long> b)
{
    return {a.F + b.F, a.S + b.S};
}

void DFS(int u, int p)
{
    vector<int> child;
    for (auto &v : adj[u]) if (v != p)
    {
        child.push_back(v);
        DFS(v, u);
    }

    bool cur = 1;
    FOR(i, 0, n) f[cur][i] = {0, -oo};
    f[cur][0] = {0, 0};

    sz[u] = 1;

    REP(i, sz(child))
    {
        cur ^= 1;
        FOR(j, 0, n) f[cur][j] = {0, -oo};

        int v = child[i];
        REP(k1, min(m, sz[u])) REP(k2, min(sz[v], m - k1))
        {
            maxi(f[cur][k1 + k2], Add(f[cur ^ 1][k1], dp[v][k2]));
            maxi(f[cur][k1 + k2 + 1], {f[cur ^ 1][k1].F + dp[v][k2].F + (dp[v][k2].S > 0), f[cur ^ 1][k1].S});
        }

        sz[u] += sz[v];
    }

    REP(k, min(m, sz[u])) dp[u][k] = {f[cur][k].F, f[cur][k].S + a[u]};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        FOR(i, 1, n) adj[i].clear();

        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n)
        {
            int x; cin >> x;
            a[i] = x - a[i];
        }
        FOR(i, 2, n)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        FOR(u, 1, n) FOR(i, 0, n) dp[u][i] = {0, -oo};
        DFS(1, -1);
        cout << dp[1][m - 1].F + (dp[1][m - 1].S > 0) << '\n';
    }

    return 0;
}