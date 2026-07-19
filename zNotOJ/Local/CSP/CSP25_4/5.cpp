#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

struct Edge
{
    int i, v, w;
};

int const N = 1e5 + 5;
int const M = 5e5 + 5;

int n, m, s, t;

vector<Edge> adj[N];

long long d[N];

void Dijkstra(int node, int edge)
{
    memset(d, 0x3f, sizeof d);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    if (s != node) 
    {
        pq.push({0, s});
        d[s] = 0;
    }

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (u == t) return;
        if (du > d[u]) continue;

        for (auto e : adj[u]) if (e.i != edge) 
        {
            int v = e.v;
            int w = e.w;

            if (v == node) continue;
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

    cin >> n >> m >> s >> t;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({i, v, w});
    }

    int q; cin >> q;
    while (q--)
    {
        char type;
        int node = -1, edge = -1;

        cin >> type >> node;
        if (type == 'E') swap(node, edge);

        Dijkstra(node, edge);
        if (d[t] > 1e18) d[t] = -1;
        cout << d[t] << '\n';
    }

    return 0;
}