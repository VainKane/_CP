#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

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
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

struct Edge
{
    int u, v;
    long long p, w;

    int GetOther(int &node)
    {
        return node ^ u ^ v;
    }

    bool operator < (Edge const other) const
    {
        return p < other.p;
    }
};

int const N = 2e5 + 5;
int const M = 3e5 + 5;
long long const oo = 2e18;

int n, m;

vector<int> adj[N];
Edge edges[M];
DSU dsu;

long long d[N];

void Dijkstra(int const &idx)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    FOR(u, 2, n) d[u] = oo;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &id : adj[u]) if (id <= idx)
        {
            int v = edges[id].GetOther(u);
            if (mini(d[v], d[u] + edges[id].w)) pq.push({d[v], v});
        }
    }

    cout << edges[idx].p << ' ' << d[n];
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        long long p, w;
        cin >> u >> v >> p >> w;
        
        edges[i] = {u, v, p, w};
    }

    dsu = DSU(n);

    sort(edges + 1, edges + m + 1);
    FOR(i, 1, m)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    FOR(i, 1, m)
    {
        dsu.Union(edges[i].u, edges[i].v);
        if (edges[i].p == edges[i + 1].p) continue;
        if (dsu.Find(1) == dsu.Find(n)) Dijkstra(i);
    }

    return 0;
}