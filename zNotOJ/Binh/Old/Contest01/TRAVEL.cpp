#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define BIT(i, x) (((x) >> (i)) & 1)
#define name "TRAVEL"

struct Edge
{
    int u, v, c1, c2;

    int Other (int p) const
    {
        return (u ^ v ^ p);
    }
};

int const N = 2e5 + 5;
int const LOG = 18;

int n;
vector<int> adj[N];
Edge edges[N];

int h[N];
int up[N][22];

int cnt[N], val[N];

long long res = 0;

void DFS(int u)
{
    for (auto i : adj[u])
    {
        int v = edges[i].Other(u);
        if (v == up[u][0]) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;
        
        DFS(v);
    }
}

void DFS2(int u)
{
    val[u] += cnt[u];
    for (auto i : adj[u])
    {
        int v = edges[i].Other(u);
        if (v == up[u][0]) continue;

        DFS2(v);
        val[u] += val[v];

        res += min(1ll * edges[i].c1 * val[v], 1ll * edges[i].c2);
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
    DFS(1);

    FOR(j, 1, LOG) FOR(u, 1, n)
        up[u][j] = up[up[u][j - 1]][j - 1];

    FOR(i, 1, n - 1)
    {
        cnt[i]++;
        cnt[i + 1]++;
        cnt[LCA(i, i + 1)] -= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n - 1)
    {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;

        edges[i] = {u, v, c1, c2};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    Init();
    DFS2(1);

    cout << res;

    return 0;
}