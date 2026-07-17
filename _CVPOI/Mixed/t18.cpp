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

int const N = 209;
int const MOD = 1e9 + 2277;
int const oo = 1e9 + 9;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;
vector<pair<int, int>> adj[N];
vector<int> dagAdj[N];

int d[N];

int deg[N];
vector<int> topo;

int f[N], g[N];
bool mark[N];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F, w = e.S;
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
        int u = q.front(); q.pop();
        topo.push_back(u);
        
        for (auto &v : dagAdj[u]) if (!--deg[v]) q.push(v);
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
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(s, 1, n)
    {
        Dijkstra(s);

        FOR(u, 1, n) dagAdj[u].clear(), f[u] = 0;
        topo.clear();

        FOR(u, 1, n) for (auto &e : adj[u])
        {
            int v = e.F, w = e.S;
            if (d[u] + w != d[v]) continue;
            dagAdj[u].push_back(v);
            deg[v]++;
        }

        BFS();
        f[s] = 1;

        for (auto &u : topo) for (auto &v : dagAdj[u]) Add(f[v], f[u]);

        FOR(t, 1, n) if (t != s && d[t] < oo)
        {
            FOR(u, 1, n) g[u] = 0;
            g[t] = 1;

            FORD(i, sz(topo) - 1, 0)
            {
                int u = topo[i];
                for (auto &v : dagAdj[u]) Add(g[u], g[v]);
            }

            FOR(u, 1, n) if (u != s && u != t)
            {
                int tmp = 1LL * f[u] * g[u] % MOD;
                mark[u] |= (tmp == f[t]);
            }
        }
    }

    bool haha = false;
    FOR(u, 1, n) if (mark[u]) cout << u << ' ', haha = true;
    if (!haha) cout << "No important cities.";

    return 0;
}