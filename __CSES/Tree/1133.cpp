#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n;
vector<int> adj[N];

int s[N];
long long f[N], fPar[N];

void DFSPrepare(int u, int p)
{
    s[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        f[u] += s[v] + f[v];
        s[u] += s[v];
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        fPar[v] = fPar[u] + f[u] - f[v] + n - 2 * s[v];
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

    FOR(u, 1, n) cout << f[u] + fPar[u] << ' ';

    return 0;
}