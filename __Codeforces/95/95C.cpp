#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

int const N = 1001;

int n, m;
int x, y;

vector<pair<int, int>> adj[N];
int t[N], c[N];

long long d[N][N];

void Dijkstra(int s, long long d[])
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (d[v] > d[u] + w && w <= 1e9)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> x >> y;

    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, n) cin >> t[i] >> c[i];

    memset(d, 0x3f, sizeof d);
    FOR(i, 1, n) Dijkstra(i, d[i]);
    
    FOR(i, 1, n) adj[i].clear();
    FOR(u, 1, n) FOR(v, 1, n) if (d[u][v] <= t[u] && u != v)
        adj[u].push_back({v, c[u]});

    memset(d[x], 0x3f, sizeof d[x]);
    Dijkstra(x, d[x]);

    cout << (d[x][y] < 1e18 ? d[x][y] : -1);

    return 0;
}