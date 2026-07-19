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

int const N = 1e5 + 5;
int MOD;

int n, m, k;
vector<pair<int, int>> adj[N];
vector<int> dagAdj[N];

int d[N];
int deg[N];

int dp[N];
vector<int> topo;

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v], d[u] + w)) 
            {
                dagAdj[v] = {{u}};
                pq.push({d[v], v});
            }
            else if (d[v] == d[u] + w) dagAdj[v].push_back(u);
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (deg[u] == 0) q.push(u);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto &v : dagAdj[u]) if (!--deg[v]) q.push(v);
    }
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Reset()
{
    FOR(u, 1, n) 
    {
        dagAdj[u].clear();
        adj[u].clear();
        dp[u] = deg[u] = 0;
    }

    topo.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> MOD;

        Reset();
        FOR(i, 1, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        Dijkstra();
        FOR(u, 1, n) for (auto &v : dagAdj[u]) deg[v]++;
        BFS();

        dp[n] = 1;
        for (auto &u : topo) for (auto &v : dagAdj[u]) Add(dp[v], dp[u]);

        cout << dp[1] << '\n';
    }

    return 0;
}