#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MK(i) (1 << (i))

int const N = 7e4 + 5;
int const LOG = 17;

int n, q;
vector<int> adj[N];

int h[N];
int lg[N];

int up[N][20];
int upLCA[N][20];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) 
            up[v][i] = up[up[v][i - 1]][i - 1];

        DFS(v, u);
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

void Init()
{
    DFS(1, -1);

    FOR(u, 1, n) upLCA[u][0] = u;
    FOR(i, 1, LOG) FOR(u, 1, n - MK(i) + 1)
        upLCA[u][i] = LCA(upLCA[u][i - 1], upLCA[u + MK(i - 1)][i - 1]);

    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;
}

int LCARange(int l, int r)
{
    int k = lg[r - l + 1];
    return LCA(upLCA[l][k], upLCA[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n)
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
        cout << LCARange(u, v) << '\n';
    }

    return 0;
}