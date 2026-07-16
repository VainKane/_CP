#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, c, d;
};

struct VOI
{
    int v, d;
};

int const N = 159;
int const M = 6009;

int n;
int m;

int s;
int t;
int w;

int d[N];

Edge a[M];
vector<VOI> adj[N];

double res = 1e9;

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du > d[u]) continue;

        for (auto e : adj[u])
        {
            int v = e.v;
            int w = e.d;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void Filter(int cmin)
{
    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= m; i++)
    {
        if (a[i].c < cmin) continue;

        adj[a[i].u].push_back({a[i].v, a[i].d});
        adj[a[i].v].push_back({a[i].u, a[i].d});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(2);

    cin >> n >> m;
    cin >> s >> t >> w;

    for (int i = 1; i <= m; i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;

        a[i] = {u, v, c, d};
    }

    for (int i = 1; i <= m; i++)
    {
        Filter(a[i].c);
        Dijkstra(s);

        res = min(res, d[t] + ((double)w / a[i].c));
    }

    cout << res;

    return 0;
}