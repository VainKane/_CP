#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define name "MINBUS"

int const N = 3e5 + 5;
int const LOG = 19;

int n;
vector<int> adj[N];

int h[N], par[N];
int up[N][20];

int res[N];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        par[v] = up[v][0] = u;

        FOR(i, 1, LOG) 
            up[v][i] = up[up[v][i - 1]][i - 1];

        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        u = up[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int Find(int v)
{
    if (res[v] == -1 || v == 0) return v;
    return par[v] = Find(par[v]);
}

void Update(int u, int lca, int id)
{
    if (h[u] < h[lca]) swap(u, lca);
    
    while (h[u] >= h[lca])
    {
        if (res[u] == -1) res[u] = id;
        u = par[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(res, -1, sizeof res);
    h[1] = 1;
    DFS(1, -1);

    int q; cin >> q;
    FOR(i, 1, q)
    {
        int u, v;
        cin >> u >> v;

        int p = LCA(u, v);
        Update(u, p, i);
        Update(v, p, i);
    }

    FOR(u, 1, n) cout << res[u] << '\n';

    return 0;
}