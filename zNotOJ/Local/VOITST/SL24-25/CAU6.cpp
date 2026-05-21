#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU6"

int const N = 2e5 + 5;
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int f[N], g[N];

int PowMod(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1ll * res * a % MOD;
        b >>= 1;
        a = 1ll * a * a % MOD;
    }
    return res;
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
    for (auto &v : adj[u]) if (v != p)
    {
        int tmp = 1ll * f[u] * g[u] % MOD;
        tmp = 1ll * tmp * PowMod((f[v] + 1) % MOD, MOD - 2) % MOD;

        g[v] = (tmp + 1) % MOD;
        DFS2(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    g[1] = 1;
    DFS1(1, -1);
    DFS2(1, -1);

    FOR(u, 1, n) cout << 1ll * f[u] * g[u] % MOD << ' ';

    return 0;
}