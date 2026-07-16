#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 1e5 + 5;

int n, MOD;
vector<int> adj[N];

int f[N], g[N];
int pre[N], suf[N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void DFS1(int u, int p)
{
    f[u] = 1;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS1(v, u);
        f[u] = 1ll * f[u] * ((f[v] + 1) % MOD) % MOD;
    }
}

void DFS2(int u, int p)
{
    vector<int> nodes = {0};
    for (auto &v : adj[u]) if (v != p) nodes.push_back(v);

    int k = nodes.size() - 1;
    suf[k + 1] = 1;

    FOR(i, 1, k) pre[i] = 1ll * pre[i - 1] * ((f[nodes[i]] + 1) % MOD) % MOD;
    FORD(i, k, 1) suf[i] = 1ll * suf[i + 1] * ((f[nodes[i]] + 1) % MOD) % MOD;

    FOR(i, 1, k)
    {
        int v = nodes[i];
        
        g[v] = 1ll * pre[i - 1] * suf[i + 1] % MOD;
        g[v] = 1ll * g[v] * g[u] % MOD;
        Add(g[v], 1);
    }

    FOR(i, 1, k) DFS2(nodes[i], u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> MOD;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pre[0] = g[1] = 1;
    DFS1(1, -1);
    DFS2(1, -1);

    FOR(u, 1, n) cout << 1ll * f[u] * g[u] % MOD << '\n';

    return 0;
}