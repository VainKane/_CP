#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define BIT(i, x) (((x) >> (i)) & 1)
#define F first
#define S second
#define name "distance"

int const N = 3e5 + 5;
int const LOG = 19;

int sub;
int n;

int h[N];
long long d[N];
vector<pair<int, int>> adj[N];

int up[N][22];

void DFS(int u, int p)
{
    for (auto e : adj[u])
    {
        int v = e.F;
        int w = e.S;
    
        if (v == p) continue;

        up[v][0] = u;
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    
    int delta = h[u] - h[v];
    FOR(i, 0, LOG) if (BIT(i, delta)) u = up[u][i];

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void Init()
{
    DFS(1, -1);

    FOR(j, 1, LOG) FOR(u, 1, n)
        up[u][j] = up[up[u][j - 1]][j - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> sub;
    cin >> n;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Init();

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << d[u] + d[v] - 2 * d[LCA(u, v)] << '\n';
    }

    return 0;
}