#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int const N = 2e5 + 5;
int const LOG = 18;

int n, q;
vector<int> adj[N];

int h[N];
int up[N][20];

int in[N];
int cnt = 0;

void DFS(int u, int p)
{
    in[u] = ++cnt;
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

bool cmp(int u, int v)
{
    return in[u] < in[v];
}

int Dist(int u, int v)
{
    int p = LCA(u, v);
    return h[u] + h[v] - 2 * h[p];
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

    DFS(1, -1);

    while (q--)
    {
        int k; cin >> k;
        vector<int> v;

        while (k--)
        {
            int node; cin >> node;
            v.push_back(node);
        }

        sort(all(v), cmp);
        v.push_back(v[0]);

        int res = 0;
        FOR(i, 1, sz(v) - 1) res += Dist(v[i], v[i - 1]);
        cout << res / 2 << '\n';
    }


    return 0;
}