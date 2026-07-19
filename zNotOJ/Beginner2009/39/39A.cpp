#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n;
vector<Edge> adj[N];
int f[N];
int g[N];

int res = 0;

void DFS(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (v == p) continue;
        DFS(v, u);
        int x = f[v] + w;
        if (x > f[u]) 
        {
            g[u] = f[u];
            f[u] = x;
        }
        else if (x > g[u]) g[u] = x;
    }
    res = max(res, f[u] + g[u]);
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

    DFS(1, -1);
    cout << res;

    return 0;
}