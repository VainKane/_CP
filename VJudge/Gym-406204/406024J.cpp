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

    void Input()
    {
        cin >> u >> v >> w;
    }

    int GetOther(int node)
    {
        return node ^ u ^ v;
    }
};

int const N = 1e5 + 5;
int const M = 2e5 + 5;
int const MOD = 1e9 + 7;
long long const oo = 1e18;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

Edge edges[M];
vector<int> adj[N];

long long d[N];
int deg[N];

vector<int> topo;
int dp[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({d[1], 1});

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &id : adj[u])
        {
            int v = edges[id].GetOther(u);
            int w = edges[id].w;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!deg[u])
    {
        dp[u] = 1;
        q.push(u);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for (auto &v : adj[u]) if (!--deg[v]) q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        edges[i].Input();
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    Dijkstra();

    FOR(u, 1, n) adj[u].clear();
    FOR(i, 1, m)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (d[u] + w == d[v]) adj[u].push_back(v), deg[v]++;
        if (d[v] + w == d[u]) adj[v].push_back(u), deg[u]++;
    }

    BFS();

    for (auto &u : topo) for (auto &v : adj[u]) Add(dp[v], dp[u]);
    FOR(u, 1, n) cout << (d[u] < oo ? d[u] : -1) << ' ' << dp[u] << '\n';

    return 0;
}