#include <bits/stdc++.h>

using namespace std;

#define name "lck"

int const N = 70009;
int const LOG = 17;
int const maxLOG = 20;

int n, q;
vector<int> adj[N];

int up[N][maxLOG];
int st[N][maxLOG];
int lg[N];
int h[N];

void DFS(int u)
{
    for (auto v : adj[u])
    {
        if (v == up[u][0]) continue;
        
        h[v] = h[u] + 1;
        up[v][0] = u;
        
        DFS(v);
    }
}

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int i = 0; i <= LOG; i++)
    {
        if (bit(i, delta)) u = up[u][i];
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[u][i] != up[v][i]) 
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void Init()
{
    DFS(1);
    for (int i = 1; i <= LOG; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }

    lg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for (int u = 1; u <= n; u++) st[u][0] = u;
    for (int i = 1; i <= LOG; i++)
    {
        for (int u = 1; u + (1 << i) - 1 <= n; u++)
        {
            st[u][i] = LCA(st[u][i - 1], st[u + (1 << (i - 1))][i - 1]);
        }
    }
}

int Query(int u, int v)
{
    int k = lg[v - u + 1];
    return LCA(st[u][k], st[v - (1 << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Init();

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << Query(u, v) << '\n';
    }

    return 0;
}