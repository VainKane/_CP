#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n;
vector<Edge> adj[N];
bool visited[N];
int d[N];
int par[N];

int dia = 0;

void DFS(int u)
{
    visited[u] = true;
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (visited[v]) continue;
        d[v] = d[u] + w;
        par[v] = u;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1);

    int node = max_element(d + 1, d + n + 1) - d;

    d[node] = 0;
    memset(visited, 0, sizeof visited);
    DFS(node);

    dia = max(dia, *max_element(d + 1, d + n + 1));

    cout << dia;

    return 0;
}