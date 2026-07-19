#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

int const N = 1009;

struct Edge
{
    int v, w;
};

int n;
int k;
int a;
int b;

vector<Edge> adj[N];

int d[N];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();

        if (du > d[u]) continue;

        for (auto e : adj[u])
        {
            int v = e.v;
            int w = e.w;

            int nxtDay = (d[u] / 12 + 1) * 12;

            if (d[u] > nxtDay + w)
            {
                d[u] = nxtDay + w;
                pq.push({d[u], u});
            }
            if (w <= nxtDay - d[u])
            {
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
            else if (d[v] > nxtDay + 12 + w)
            {
                d[v] = nxtDay + 12 + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    cin >> n >> k;

    while (k--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (w > 12) continue;
        adj[u].push_back({v, w});
    }   

    Dijkstra(a);
    cout << d[b];

    return 0;
}