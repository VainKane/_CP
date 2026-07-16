#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second

struct Edge
{
    int v, w;
};

int const N = 1009;

int n;
int m;
int k;

vector<Edge> adj[N];
long long d[N][109];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s][1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u][k]) continue;

        for (auto e : adj[u])
        {
            int v = e.v;
            int w = e.w;

            long long l = du + w;
            int p = lower_bound(d[v] + 1, d[v] + k + 1, l) - d[v];

            if (p > k) continue;
            if (d[v][p] == l) continue;

            for (int j = k; j >= p; j--)
            {
                d[v][j] = d[v][j - 1];
            }

            d[v][p] = l;
            pq.push({d[v][p], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra(1);

    if (d[n][1] == d[n][101])
    {
        cout << -1;
        exit(0);
    }

    for (int i = 1; i <= k; i++)
    {
        if (d[n][i] == d[n][101])
        {
            d[n][i] = d[n][i - 1] + 2ll * d[n][1];
        }

        cout << d[n][i] << ' ';
    }

    return 0;
}