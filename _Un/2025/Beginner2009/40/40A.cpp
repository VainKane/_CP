#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n;
vector<Edge> adj[N];

int s[N];
long long f[N];
long long g[N];

int sum = 0;

void DFS1(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;
        if (v == p) continue;

        DFS1(v, u);
        s[u] += s[v];
        f[u] += f[v] + 1ll * s[v] * w;
    }
}

void DFS2(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;
        if (v == p) continue;
        
        g[v] = g[u] + (f[u] - f[v] - 1ll * s[v] * w) + 1ll * (sum - s[v]) * w;
        DFS2(v, u); 
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

    for (int u = 1; u <= n; u++) 
    {
        cin >> s[u];
        sum += s[u];
    }

    DFS1(1, -1);
    DFS2(1, -1);

    long long mi = 1e18;
    long long ma = 0;

    for (int u = 1; u <= n; u++)
    {
        mi = min(mi, f[u] + g[u]);
        ma = max(ma, f[u] + g[u]);
    }

    cout << mi << ' ' << ma;

    return 0;
}