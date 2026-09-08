#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, i;
};

int const N = 1e5 + 5;

int n;
int m;

vector<Edge> adj[N];
int low[N];
int id[N];
int par[N];

long long res[N];
int val[N];

int cnt = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    val[u]++;

    for (auto e : adj[u])
    {
        int v = e.v;
        if (v == par[u]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            val[u] += val[v];

            if (low[v] == id[v])
            {
                res[e.i] = 1ll * val[v] * (n - val[v]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);
    for (int i = 1; i <= m; i++) cout << res[i] << '\n';

    return 0;
}