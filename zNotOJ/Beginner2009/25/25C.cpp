#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;

vector<int> adj[N];
int up[N][LOG + 2];
int h[N];

int cnt[N];
int val[N];

int res = 0;
int root = 1;

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
        for (int i = 1; i <= LOG; i++)
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

    for (int i = LOG; i >= 0; i--)
    {
        if (bit(i, d))
        {
            u = up[u][i];
        }
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

void DFSCheck(int u)
{
    val[u] += cnt[u];
    for (auto v : adj[u])
    {
        if (v == up[u][0]) continue;
        
        DFSCheck(v);
        val[u] += val[v];
    
        // cout << "debug: " << v << ' ' << val[v] << '\n';
    }

    res += (!val[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);

    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        int anc = LCA(u, v);
        cnt[anc] -= 2;
        cnt[u] += 1;
        cnt[v] += 1;
    }

    DFSCheck(1);

    cout << res - 1;

    return 0;
}