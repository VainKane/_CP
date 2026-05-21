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

struct Edge
{
    int u, v, w;
};

int const N = 1509;
int const M = 5009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

vector<int> adj[N];
vector<int> dagAdj[N];
Edge edges[M];

int d[N];

vector<int> topo;
int deg[N];

int f[N], g[N];

bool used[M];
int res[M];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
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
            int v = edges[id].v;
            int w = edges[id].w;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!deg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (auto &id : dagAdj[u])
        {
            int v = edges[id].v;
            if (!--deg[v]) q.push(v);
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

        adj[u].push_back(i);
        edges[i] = {u, v, w};
    }

    FOR(s, 1, n)
    {
        FOR(u, 1, n) dagAdj[u].clear(), deg[u] = f[u] = g[u] = 0;
        memset(used, false, sizeof used);
        topo.clear();

        Dijkstra(s);

        FOR(i, 1, m)
        {
            int u = edges[i].u, v = edges[i].v;
            if (d[u] + edges[i].w == d[v])
            {
                dagAdj[u].push_back(i);
                deg[v]++;
                g[u]++;
                used[i] = true;
            }
        }

        BFS();
        f[s] = 1;

        for (auto &u : topo) for (auto &id : dagAdj[u])
        {
            int v = edges[id].v;
            Add(f[v], f[u]);
        }

        FORD(i, sz(topo) - 1, 0)
        {
            int u = topo[i];

            for (auto &id : dagAdj[u])
            {
                int v = edges[id].v;
                Add(g[u], g[v]);
            }
        }

        FOR(i, 1, m) if (used[i]) res[i] = (res[i] + 1LL * f[edges[i].u] * (g[edges[i].v] + 1)) % MOD;
    }

    FOR(i, 1, m) cout << res[i] << '\n';

    return 0;
}