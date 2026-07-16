#include <bits/stdc++.h> 

using namespace std;

int const N = 1e5 + 5;
int const M = 17;

int n;
int m;
int k;

bool visisted[N];
int up[N][M + 5];
int h[N];
vector<int> adj[N];

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

void DFS(int u)
{
    for (auto v : adj[u])
    {
        if (v == up[u][0]) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;

        for (int i = 1; i <= M; i++)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }

        DFS(v);
    }
}

int LCA(int u, int v)
{
    if (h[v] > h[u]) swap(u, v);

    int d = h[u] - h[v];
    for (int i = M; i >= 0; i--)
    {
        if (bit(i, d)) u = up[u][i];
    }

    if (u == v) return u;

    for (int i = M; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(k);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}