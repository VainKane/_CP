#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n, m, l;
vector<Edge> adj[N];
bool visited[N];

int f[N];
int g[N];
int par[N];

int r[N];

int cc = 0;
int res = 0;

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

void DFS2(int u)
{
    visited[u] = true;
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (visited[v]) continue;

        int k = f[u];
        if (f[v] + w == f[u]) k = g[u];
        par[v] = w + max(k, par[u]);

        DFS2(v);
    }

    // d[cc] = max(d[cc], f[u] + g[u]);
    res = max(res, f[u] + g[u]);
    r[cc] = min(r[cc], max(f[u], par[u]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(r, 0x7f, sizeof r);
    for (int u = 0; u < n; u++) 
    {
        if (!visited[u])
        {
            cc++;
            DFS1(u, -1);
            DFS2(u);
        }
    }

    int r1 = 0;
    int r2 = 0;
    int r3 = 0;

    for (int i = 1; i <= cc; i++)
    {
        if (r[i] > r1)
        {
            r3 = r2;
            r2 = r1;
            r1 = r[i];
        }
        else if (r[i] > r2)
        {
            r3 = r2;
            r2 = r[i];
        }
        else if (r[i] > r3) r3 = r[i];
    }

    if (n - m - 1 >= 1) res = max(res, r1 + l + r2);
    if (cc >= 3 && n - m - 1 >= 2) res = max(res, r2 + 2 * l + r3);

    cout << res;
  
    return 0;
}