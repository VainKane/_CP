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
#define name "02"

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int u, v, w;

    int GetOther(int node)
    {
        return node ^ u ^ v;
    }
};

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n, cnt;

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
        n = cnt = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        return par[v] == v ? v : Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b];
        par[b] = a;
        cnt--;
    }
};

int const N = 1009;
int const oo = 1e9 + 2;

int n, m, q, v;
int node[N];

Edge edges[N];
vector<int> adj[N];

DSU dsu;

int d[N][N];
int par[N][N];

void Dijkstra(int s, int d[], int par[])
{
    memset(d, 0x3f, (n + 1) * sizeof (int));
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &id : adj[u])
        {
            int v = edges[id].GetOther(u);
            int w = edges[id].w;

            if (mini(d[v], d[u] + w)) 
            {
                par[v] = id;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q >> v;
    
    FOR(i, 1, m)
    {
        int u, v, c, x;
        cin >> u >> v >> c >> x;
        edges[i] = {u, v, c};
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    FOR(i, 1, q) cin >> node[i];

    FOR(i, 1, q) Dijkstra(node[i], d[node[i]], par[node[i]]);
    dsu = DSU(n);

    int res = oo;
    vector<int> haha; 
    
    FOR(i, 1, q)
    {
        vector<int> nodes = {node[i]};
        vector<int> used;
        int cost = 0;
        
        FOR(j, 1, q) 
        {
            int dist = oo;
            int v = 0;

            for (auto &u : nodes)
            {
                if (dsu.Find(u) == dsu.Find(node[j])) continue;
                if (mini(dist, d[u][node[j]])) v = u;
            }

            if (v == 0) break;

            int x = node[j];
            while (x != v)
            {
                nodes.push_back(x);
                dsu.Union(x, v);

                Edge &e = edges[par[v][x]];
                used.push_back(par[v][x]);       
                x = e.GetOther(x);
                cost += e.w;
            }
        }

        if (mini(res, cost)) haha = used;
    }

    if (res == oo) cout << -1;
    else
    {
        cout << res << '\n' << sz(haha);
        for (auto &id : haha) cout << id << ' ';
    }

    return 0;
}