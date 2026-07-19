#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define BIT(i, x) (((x) >> (i)) & 1)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int u, v;

    int Other(int p)
    {
        return p ^ u ^ v;
    }  
};

int const N = 2e5 + 5;
int const LOG = 18;

int n, m;
vector<int> adj[N];
Edge edges[N];

bool mark[N];
vector<int> bridges;

int id[N], low[N];
int timer = 0;

int cc = 0;
int ccId[N];

int val[N];

int h[N], d[N];
int up[N][20];

void Tarjan(int u, int p)
{
    low[u] = id[u] = ++timer;

    for (auto &i : adj[u])
    {
        int v = edges[i].Other(u);
        if (v == p) continue;

        if (id[v]) mini(low[u], id[v]);
        else
        {
            Tarjan(v, u);

            mini(low[u], low[v]);
            if (low[v] == id[v]) 
            {
                mark[i] = true;
                bridges.push_back(i);
            }
        } 
    }
}

void DFSPrepare(int u, int &id)
{
    ccId[u] = id;
    for (auto &i : adj[u]) if (!mark[i])
    {
        int v = edges[i].Other(u);
        val[id]++;

        if (!ccId[v]) DFSPrepare(v, id);
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        d[v] = val[v] + d[u] + 1;
        h[v] = h[u] + 1;

        up[v][0] = u;
        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];

        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    FOR(i, 0, LOG) if (BIT(i, delta)) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(id, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(id);
        adj[v].push_back(id);
        edges[id] = {u, v};
    }

    Tarjan(1, -1);
    FOR(u, 1, n) if (!ccId[u]) 
    {
        DFSPrepare(u, ++cc);
        val[cc] >>= 1;
    }

    FOR(u, 1, n) adj[u].clear();
    for (auto &i : bridges)
    {
        int u = ccId[edges[i].u];
        int v = ccId[edges[i].v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    d[1] = val[1];
    DFS(1, -1);

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        u = ccId[u];
        v = ccId[v];
        int p = LCA(u, v);

        int res1 = h[u] + h[v] - 2 * h[p];
        int res2 = d[u] + d[v] - 2 * d[p] + val[p];

        cout << res1 << ' ' << res2 << '\n';
    }

    return 0;
}