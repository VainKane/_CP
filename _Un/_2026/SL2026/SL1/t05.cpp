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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const M = 3e5 + 5;

struct Edge
{
    int u, v;
    ll p, w;

    int Other(int node) { return node ^ u ^ v; }
    void Input() { cin >> u >> v >> p >> w; }
    bool operator < (Edge const other) const { return p < other.p; }
};

struct DSU
{
    vector<int> par, sz;
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
        par = sz = vector<int>(n + 5, 0);
        MakeSet();
    }

    int Find(int v) { return par[v] == v ? v : par[v] = Find(par[v]); }

    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};

int n, m;

Edge edges[M];
vector<int> adj[N];

DSU dsu;
ll d[N];

void Dijkstra(int idx)
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({d[1], 1});

    while (!pq.empty())
    {
        int u = pq.top().S;
        ll du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &i : adj[u])
        {
            if (edges[i].p > edges[idx].p) break;
            int v = edges[i].Other(u);

            if (mini(d[v], d[u] + edges[i].w)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m) edges[i].Input();

    sort(edges + 1, edges + m + 1);
    FOR(i, 1, m)
    {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    dsu = DSU(n);
    FOR(i, 1, m)
    {
        dsu.Union(edges[i].u, edges[i].v);
        if (dsu.Find(1) == dsu.Find(n))
        {
            Dijkstra(i);
            cout << edges[i].p << ' ' << d[n];
            break;
        }
    }

    return 0;
}