#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

struct Edge
{
    int u, v, w;
    
    bool operator < (Edge const other) const
    {
        return w > other.w;
    }
};

int const N = 3009;
int const M = 1e5 + 5;

int n, m;

Edge edges[M];
vector<pair<int, int>> adj[N];

int d[N][N];
int par[N], sz[N];

int GCD(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
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

void Kruskal()
{
    sort(edges + 1, edges + m + 1);

    FOR(i, 1, m) 
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (Union(u, v))
        {
            adj[u].push_back({v, edges[i].w});
            adj[v].push_back({u, edges[i].w});
        }
    }
}

void DFS(int u, int p, int d[])
{
    for (auto e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        d[v] = min(d[u], w);
        DFS(v, u, d);
    }
}

void Init()
{
    memset(d, 0x3f, sizeof d);
    MakeSet();
    Kruskal();
    FOR(i, 1, n) DFS(i, -1, d[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("MAXPATH.inp", "r", stdin);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    Init();

    long long res = 0;
    int cnt = 0;

    FOR(u, 1, n) FOR(v, u + 1, n) if (GCD(u, v) == 1)
    {
        res += d[u][v];
        cnt++;

        // cout << cnt << ' ';
    }

    cout << fixed << setprecision(2) << (double)res / cnt;

    return 0;
}