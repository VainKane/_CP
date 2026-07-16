#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 2e5 + 5;
int const LOG = 18;

int n, m;
vector<int> adj[N];

int h[N], f[N];
int up[N][20];

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];

        DFSPrepare(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        u = up[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] += f[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        
        int p = LCA(u, v);
        f[u]++; f[v]++;
        f[p]--; f[up[p][0]]--;
    }

    DFS(1, -1);
    FOR(u, 1, n) cout << f[u] << ' ';

    return 0;
}