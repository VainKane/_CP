#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1009;

int n;
int m;

bool visisted[N];

int d1[N];
int d2[N];

vector<Edge> adj[N];

int res = 0;
int t[N];

void Dijkstra(int s, int d[])
{
    memset(visisted, 0, sizeof visisted);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (visisted[u]) continue;
        visisted[u] = true;

        for (auto e : adj[u])
        {
            int v = e.v;
            int w = e.w;

            if (d[v] > d[u] + w)
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
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(d1, 0x3f, sizeof d1);
    memset(d2, 0x3f, sizeof d2);

    Dijkstra(1, d1);
    Dijkstra(2, d2);

    for (int i = 1; i <= n; i++)
    {
        res += d1[i];
        t[i] = d2[i] - d1[i];
    }

    sort(t + 1, t + n + 1);

    for (int i = 1; i <= n / 2; i++)
    {
        res += t[i];
    }

    cout << res;

    return 0;
}