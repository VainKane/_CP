#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n; 

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;

        return true;
    }
};

struct Edge
{
    int u, v, w;

    bool operator < (Edge const other) const
    {
        return w < other.w;
    }
};

int const N = 2e5 + 5;
int const LOG = 18;

int n, m, q;

vector<pair<int, int>> adj[N];
Edge edges[N];
DSU dsu;

int h[N];
int up[N][20];
int upMax[N][20];

vector<int> mst;

void Kruskal()
{
    sort(edges + 1, edges + m + 1);
    FOR(i, 1, m) 
    {
        if (sz(mst) == n - 1) break;
        if (dsu.Union(edges[i].u, edges[i].v)) mst.push_back(i);
    }
}

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;
        upMax[v][0] = w;

        FOR(i, 1, LOG)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
            upMax[v][i] = max(upMax[v][i - 1], upMax[up[v][i - 1]][i - 1]);
        }

        DFS(v, u);
    }
}

int GetMax(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    int res = 0;

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        maxi(res, upMax[u][i]);
        u = up[u][i];

        // cout << "debug: " << i << '\n';
    }

    if (u == v) return res;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        maxi(res, max(upMax[u][i], upMax[v][i]));
        u = up[u][i];
        v = up[v][i];
        // cout << "debug: " << upMax[u][i] << ' ' << upMax[v][i] << '\n';
    }

    maxi(res, max(upMax[u][0], upMax[v][0]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    dsu = DSU(n);
    Kruskal();

    for (auto &id : mst) 
    {
        int u = edges[id].u;
        int v = edges[id].v;
        int w = edges[id].w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1);

    while (q--) 
    {
        int u, v;
        cin >> u >> v;
        cout << GetMax(u, v) << '\n';
    }

    // FOR(u, 1, n)
    // {
    //     cout << "adj of " << u << ": ";
    //     for (auto &e : adj[u]) cout << e.F << ' ';
    //     cout << '\n';
    // }

    // FOR(i, 1, m) cout << edges[i].u << ' ' << edges[i].v << ' ' << edges[i].w << '\n';

    // cout << "debug: " << upMax[6][1];

    return 0;
}