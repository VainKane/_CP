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
vector<int> hahaAdj[N];

int d[N];
int dp[N][55];

bool visited[N];

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
            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

bool DFS(int u)
{
    visited[u] = true;
    for (auto &v : hahaAdj[u])
    {
        if (visited[v]) return false;
        if (!DFS(v)) return false;
    }

    return true;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> MOD;
        
        FOR(u, 1, n) 
        {
            hahaAdj[u].clear();
            adj[u].clear();
        }

        FOR(i, 1, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});

            if (!w) hahaAdj[u].push_back(v);
        }

        Dijkstra();

        memset(dp, 0, sizeof dp);
        dp[1][0] = 1;

        FOR(j, 0, k) FOR(u, 1, n) for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            int delta = j + d[u] + w - d[v];
            if (delta > k) continue;

            Add(dp[v][delta], dp[u][j]);
        }

        int res = 0;
        FOR(i, 0, k) Add(res, dp[n][i]);

        memset(visited, false, sizeof visited);
        FOR(u, 1, n) if (!visited[u]) if (!DFS(u)) res = -1;

        cout << res << '\n';
    }

    return 0;
}