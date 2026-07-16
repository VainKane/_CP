#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int f[N][2];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void DFS(int u, int p)
{
    f[u][0] = f[u][1] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);

        f[u][1] = 1ll * f[u][1] * f[v][0] % MOD;
        f[u][0] = 1ll * f[u][0] * (f[v][0] + f[v][1]) % MOD;
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

    DFS(1, -1);
    cout << (f[1][0] + f[1][1]) % MOD;

    return 0;
}