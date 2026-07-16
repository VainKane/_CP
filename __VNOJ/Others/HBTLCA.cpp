#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 1e5 + 5;
int const LOG = 17;

int n;
vector<int> adj[N];

int h[N];
int up[N][20];

int root = 1;

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p) 
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true)
    {
        cin >> n;
        if (!n) return 0;

        FOR(u, 1, n) adj[u].clear();
        h[root = 1] = 0;

        FOR(i, 2, n) 
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFS(1, -1);

        int q; cin >> q;
        while (q--)
        {
            char type;
            int u, v;
            
            cin >> type;
            if (type == '!') cin >> root;
            else
            {
                cin >> u >> v;
                int p = LCA(u, v);
                int res = LCA(u, root) ^ LCA(v, root) ^ LCA(u, v);
                cout << res << '\n';
            }
        }
    }

    return 0;
}