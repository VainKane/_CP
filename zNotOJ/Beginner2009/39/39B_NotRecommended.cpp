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
int d1[N];
int d2[N];

int rad = 1e9;

void DFS(int u, int d[])
{
    visited[u] = true;
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (visited[v]) continue;
        d[v] = d[u] + w;
        DFS(v, d);
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

    DFS(1, d1);
    int a = max_element(d1 + 1, d1 + n + 1) - d1;
    
    memset(visited, 0, sizeof visited);
    d1[a] = 0;
    DFS(a, d1);
    int b = max_element(d1 + 1, d1 + n + 1) - d1;

    memset(visited, 0, sizeof visited);
    d2[b] = 0;
    DFS(b, d2);

    for (int u = 1; u <= n; u++)
    {
        int ecc = max(d1[u], d2[u]);
        rad = min(rad, ecc);
    }

    cout << rad;

    return 0;
}