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

    void Union(int a, int b)
    {
        if (a == b) return;
        
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

struct Edge
{
    int u, v, w, id;

    bool operator < (Edge const other) const
    {
        return w < other.w;
    }
};

int const N = 1e5 + 5;

int n, m;
Edge edges[N];

vector<pair<int, int>> adj[N];

int res[N];

int par[N];
int sz[N];

int low[N], in[N];
int timer = 0;

DSU dsu;
multiset<pair<int, int>> s;

void Add(int a, int b, int &id)
{
    a = dsu.Find(a);
    b = dsu.Find(b);

    if (a == b) return;
    
    res[id] = 1;
    adj[a].push_back({b, id});
    adj[b].push_back({a, id});

    s.insert({a, b});
    s.insert({b, a});
}

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;

    for (auto &e : adj[u])
    {
        int v = e.F;

        if (v == p) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);
            if (low[v] == in[v])
            {
                if (s.count({u, v}) == 1) res[e.S] = 2;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }

    sort(edges + 1, edges + m + 1);
    dsu = DSU(n);

    for (int i = 1; i <= m;)
    {
        int j = i;
        timer = 0;

        for (j = i; edges[i].w == edges[j].w; j++) 
            Add(edges[j].u, edges[j].v, edges[j].id);
        
        for (j = i; edges[i].w == edges[j].w; j++)
        {
            int u = dsu.Find(edges[j].u);
            if (!in[u]) Tarjan(u, -1);
        }

        for (j = i; edges[i].w == edges[j].w; j++) 
        {
            int u = dsu.Find(edges[j].u);
            int v = dsu.Find(edges[j].v);
            
            adj[u].clear(); adj[v].clear();
            in[u] = in[v] = 0;
            
            dsu.Union(u, v);
        }

        s.clear();
        i = j;
    }

    FOR(i, 1, m)
    {
        if (res[i] == 1) cout << "at least one\n";
        else if (res[i] == 2) cout << "any\n";
        else cout << "none\n";
    }

    return 0;
}