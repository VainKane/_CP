#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n;
vector<int> adj[N];

int f[N], g[N];
int fPar[N];

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        
        if (f[v] + 1 > f[u])
        {
            g[u] = f[u];
            f[u] = f[v] + 1;
        }
        else maxi(g[u], f[v] + 1);
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        int maxChild = f[u] == f[v] + 1 ? g[u] : f[u];
        fPar[v] = max(maxChild, fPar[u]) + 1;
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    FOR(u, 1, n) cout << max(f[u], fPar[u]) << ' ';

    return 0;
}