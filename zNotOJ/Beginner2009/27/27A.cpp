#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, h, w;
};

struct VOI
{
    int v, w;
};

int const N = 1e5 + 5;

int n;
int m;

int s;
int t;

Edge a[2 * N];
vector<VOI> adj[N];

long long d[N];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
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
            int w = e.w;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void Filter(int h)
{
    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= m; i++)
    {
        if (a[i].h < h) continue;
        adj[a[i].u].push_back({a[i].v, a[i].w});
        adj[a[i].v].push_back({a[i].u, a[i].w});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s >> t;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, h, w;
        cin >> u >> v >> h >> w;

        a[i] = {u, v, h, w};
    }

    int l = 1;
    int r = 1e9;

    pair<int, long long> res;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        
        Filter(mid);
        Dijkstra(s);

        if (d[t] != d[n + 1])
        {
            res = {mid, d[t]};
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res.first << ' ' << res.second;

    return 0;
}