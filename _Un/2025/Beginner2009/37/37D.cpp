#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 5;
int const MOD = 2021;

int n, m;

int a[N];
vector<int> adj[N];
int par[N];

int f[N];
vector<int> nodes;

int res = 0;

void DFS(int u)
{
    f[u] = 1;
    for (auto val : nodes)
    {
        if (val == a[u])
        {
            f[u] = 0;
            break;
        }
    }

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        par[v] = u;
        DFS(v);
        f[u] *= f[v] + 1;
        f[u] %= MOD;
    }
}

int Cal()
{
    int res = 0;
    // memset(par, 0, sizeof par);

    DFS(1);
    
    for (int u = 1; u <= n; u++)
    {
        res += f[u];
        res %= MOD;
    }

    return res;
}

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int mask = 0; mask < (1 << m); mask++)
    {
        int k = __builtin_popcount(mask);

        nodes.clear();
        for (int i = 0; i < m; i++) if (bit(i, mask)) nodes.push_back(i + 1);
        
        int x = Cal();

        if (k & 1)
        {
            res = (res - x + MOD) % MOD;
        }
        else res = (res + x) % MOD;
    }

    cout << res;

    return 0;
}