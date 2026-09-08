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
int par[N];

int res = 1e9;

void DFS1(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (v == p) continue;
        DFS1(v, u);
        int x = f[v] + w;
        if (x > f[u])
        {
            g[u] = f[u];
            f[u] = x;
        }
        else if (x > g[u]) g[u] = x;
    }    
}

void DFS2(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (v == p) continue;

        int k = f[u];
        if (f[u] == f[v] + w) k = g[u];
        par[v] = w + max(k, par[u]);
        
        DFS2(v, u);
    }
    res = min(res, max(f[u], par[u]));
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

    DFS1(1, -1);
    DFS2(1, -1);

    cout << res;

    return 0;
}