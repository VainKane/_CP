#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
    bool used = false;
};

struct Node
{
    int v, l;
};

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;
Edge a[N];

int par[N];
int sz[N];

vector<Node> adj[N];

int h[N];
int up[N][LOG + 5];
int upMin[N][LOG + 5];

long long res = 0;

int root = 1;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

void MakeSet()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int v)
{
    if (v == par[v]) return v;
    return par[v] = Find(par[v]);
}

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return false;
    
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];

    return true;
}

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

void Kruskal()
{
    MakeSet();
    sort(a + 1, a + m + 1, cmp);
    int mst = 0;

    for (int i = 1; i <= m; i++)
    {
        if (mst == n - 1) break;

        int u = a[i].u;
        int v = a[i].v;

        if (Union(u, v))
        {
            mst++;
            a[i].used = true;
            
            adj[u].push_back({v, a[i].w});
            adj[v].push_back({u, a[i].w});

            root = u;
        }
    }
}

void DFS(int u)
{
    for (auto node : adj[u])
    {
        int v = node.v;
        if (v == up[u][0]) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;
        upMin[v][0] = node.l;
        
        for (int i = 1; i <= LOG; i++)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
            upMin[v][i] = min(upMin[v][i - 1], upMin[up[v][i - 1]][i - 1]);
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

int GetMin(int anc, int u)
{
    int d = h[u] - h[anc];
    int res = 1e9;
    
    for (int i = LOG; i >= 0; i--)
    {
        if (bit(i, d))
        {
            res = min(res, upMin[u][i]);
            u = up[u][i];
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }

    Kruskal();
    DFS(root);

    for (int i = 1; i <= m; i++)
    {
        if (!a[i].used)
        {
            int u = a[i].u;
            int v = a[i].v;
            int anc = LCA(u, v);

            res += max(0ll, 1ll * min(GetMin(anc, u), GetMin(anc, v)) - a[i].w);
        }
    }

    cout << res;

    return 0;
}