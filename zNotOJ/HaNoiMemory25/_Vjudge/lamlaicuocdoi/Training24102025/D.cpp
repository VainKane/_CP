#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3009;
int const MOD = 1e9 + 7;

int n, m, s, t;
vector<pair<int, int>> adj[N];
vector<int> revDagAdj[N];
vector<int> dagAdj[N];

long long d[N];

bool visited[N];
bool inDeg[N];
vector<int> topo;

int f[N], g[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u]) 
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v], d[u] + w)) 
            {
                revDagAdj[v].clear();
                revDagAdj[v].push_back(u);
                pq.push({d[v], v});
            }
            else if (d[v] == d[u] + w) revDagAdj[v].push_back(u);
        }
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (auto &v : revDagAdj[u]) if (!visited[v]) DFS(v);
    topo.push_back(u);
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
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
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> s >> t;

    Dijkstra();
    
    FOR(u, 1, n) for (auto &v : revDagAdj[u]) 
    {
        dagAdj[v].push_back(u);
        inDeg[v] = true;
    }

    DFS(t);

    g[topo[0]] = 1;
    for (auto &u : topo) for (auto &v : dagAdj[u]) Add(g[v], g[u]);

    FOR(i, 1, sz(topo) - 1)
    {
        int u = topo[i];
        f[u] = (1ll * g[u] * g[u] - g[u] + MOD) % MOD;

        REP(j, i)
        {
            int v = topo[j];
            Sub(f[u], f[v]);
        }
    }

    cout << f[t];
    // FOR(u, 1, n) cout << g[u] << ' ';
    // cout << '\n';
    // FOR(u, 1, n) cout << f[u] << ' ';

    // cout << '\n';
    // cout << "topo: ";
    // REP(i, sz(topo)) cout << topo[i] << ' ';
    // cout << '\n';

    // cout << inv2;

    // FOR(u, 1, n)
    // {
    //     cout << "Dag adj of " << u << ": ";
    //     for (auto &v : dagAdj[u]) cout << v << ' ';
    //     cout << '\n';
    // }

    return 0;
}