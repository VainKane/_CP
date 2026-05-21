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
int const MOD = 998244353;
int const LOG = 17;

int n, q;
vector<int> adj[N];

int up[N][22];
int h[N];

int f[N], g[N];
int s[N];

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return res;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void DFSPrepare(int u, int p)
{
    f[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFSPrepare(v, u);
        
        f[u] = 1LL * f[u] * (f[v] + 1) % MOD;
    }

    s[u] = f[u];
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        g[v] = 1LL * f[u] * g[u] % MOD;
        g[v] = (1LL * g[v] * PowMod(f[v] + 1, MOD - 2) + 1) % MOD;

        Add(s[v], s[u]);

        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (up[u][i] && h[up[u][i]] >= h[v]) u = up[u][i];

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void Reset()
{
    FOR(u, 1, n) 
    {
        memset(up[u], 0, sizeof up[u]);
        adj[u].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    g[1] = 1;

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> q;
        Reset();
        
        FOR(i, 2, n)
        {
            int p; cin >> p;
            
            adj[i].push_back(p);
            adj[p].push_back(i);
        }

        DFSPrepare(1, -1);
        DFS(1, -1);

        while (q--)
        {
            int u, v;
            cin >> u >> v;

            int p = LCA(u, v);
            int res = (1LL * f[p] * g[p] + s[u] + s[v] - 2 * s[p] + 2 * MOD) % MOD;
            cout << res << '\n';
        }
    }

    return 0;
}