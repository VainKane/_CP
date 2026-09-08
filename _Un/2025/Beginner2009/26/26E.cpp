#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 109;

int n;
vector<Edge> adj[N];

int d[N];

void Dijsktra()
{
    memset(d, 0x3f, sizeof d);
    d[n] = d[2 * n] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n});
    pq.push({0, 2 * n});

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int u;
    while (cin >> u)
    {
        int v, w1, w2;
        char l;

        cin >> v >> w1 >> w2 >> l;

        if (l == 'M') u += n;
        else v += n;

        adj[u].push_back({v, w1});
        adj[v].push_back({u, w2});
    }

    Dijsktra();

    cout << min(d[1], d[n + 1]);

    return 0;
}