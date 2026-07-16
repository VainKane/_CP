#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define name "C"

struct Edge
{
    int v, w;
};

int const N = 1e4 + 5;

int n, m, k;
int s, t;

vector<Edge> adj[N];
vector<Edge> adjTmp[N];

int d[N];

int res = 1e9;

void Reset()
{
    for (int i = 1; i <= n; i++) adj[i] = adjTmp[i];
}

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adjTmp[u].push_back({v, w});
    }

    Dijkstra(s);
    res = min(res, d[t]);

    for (int i = 1; i <= k; i++)
    {
        int u, v, q;
        cin >> u >> v >> q;

        Reset();
        adj[u].push_back({v, q});
        adj[v].push_back({u, q});

        Dijkstra(s);
        res = min(res, d[t]);
    }

    if (res == 1e9) res = -1;
    cout << res;
    cerr << res << '\n';

    return 0;
}