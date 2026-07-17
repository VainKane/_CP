#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];

long long d[N];
int par[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

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

            if (d[v] > d[u] + w)
            {
                par[v] = u;
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
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra();
   
    if (d[n] > 1e18)
    {
        cout << -1;
        return 0;
    }

    vector<int> res;
    
    res.push_back(n);
    while (par[n]) res.push_back(n = par[n]);
    reverse(all(res));

    for (auto v : res) cout << v << ' ';

    return 0;
}