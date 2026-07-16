#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define sz(v) ((int)v.size())
#define F first
#define S second

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

int const N = 2e6 + 5;
int const LOG = 21;

int n, m;
bool a[N];
vector<pair<int, int>> adj[N];

DSU dsu;
vector<int> cc[N];

int up[N][25];
int h[N];

int f[N];
int cnt[N];

vector<pair<int, int>> q;
vector<int> roots;
vector<int> res;

void DFSPrepare(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFSPrepare(v, u);
    }
}

void DFS(int u, int p)
{
    for (auto &e : adj[u]) 
    {
        int v = e.F;
        int id = e.S;

        if (v == p) continue;
        DFS(v, u);
        
        f[u] += f[v];
        cnt[id] += f[v];
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    
    dsu = DSU(n);

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        if (dsu.Union(u, v)) 
        {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    FOR(i, 1, n) cc[dsu.Find(i)].push_back(i);
    FOR(u, 1, n) if (sz(cc[u])) 
    {
        roots.push_back(u);
        DFSPrepare(u, -1);
    }

    FOR(id, 1, n)
    {
        vector<int> v;
        for (auto &u : cc[id]) if (!a[u]) v.push_back(u);

        if (sz(v) & 1)
        {
            cout << -1;
            return 0;
        }

        for (int i = 1; i < sz(v); i += 2) q.push_back({v[i], v[i - 1]});
    }

    for (auto &p : q)
    {
        int lca = LCA(p.F, p.S);

        f[p.F]++; f[p.S]++;
        f[lca] -= 2;
    }

    for (auto &u : roots) DFS(1, -1);
    FOR(i, 1, m) if (cnt[i] & 1) res.push_back(i);

    cout << sz(res) << '\n';
    for (auto &id : res) cout << id << ' ';

    return 0;
}