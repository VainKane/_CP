#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

#define pb push_back

int const N = 1e5 + 5;

int n;
int m;

vector<Edge> adj[N];
bool visisted[N];

vector<int> topo;
int d[N];

void DFS(int u)
{
    visisted[u] = true;
    for (auto e : adj[u])
    {
        int v = e.v;
        if (!visisted[v]) DFS(v);
    }

    topo.pb(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].pb({v, w});

    }

    for (int i = 1; i <= n; i++) if (!visisted[i]) DFS(i);

    // for (auto val : topo) cout << val << ' ';
    // cout << '\n';

    for (auto u : topo)
    {
        for (auto e : adj[u])
        {
            d[u] = max(d[u], d[e.v] + e.w);
        }
    }

    cout << *max_element(d + 1, d + n + 1);

    return 0;
}