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
#define name "BALLOON"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

int n, m;
vector<ii> adj[N], dagAdj[N];

ll d[N], dp[N];

int deg[N];
vector<int> topo;

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({d[0], 0});

    while (!pq.empty())
    {
        int u = pq.top().S;
        ll du = pq.top().F;
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
    FOR(u, 0, n) if (!deg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (auto &e : dagAdj[u])
        {
            int v = e.F;
            if (!--deg[v]) q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra();

    FOR(u, 0, n) for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (d[u] + w == d[v]) dagAdj[u].push_back({v, w}), deg[v]++;
    }

    BFS();

    for (auto &u : topo) for (auto &e : dagAdj[u])
    {
        int v = e.F, w = e.S;
        maxi(dp[v], d[u] + w);
    }

    return 0;
}