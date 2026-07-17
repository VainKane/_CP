#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;
int MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int f[N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

void DFS(int u, int p)
{
    f[u] = 1;
    
    for (auto v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] = 1ll * f[u] * f[v] % MOD;
    }
    
    Add(f[u], 1);
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

    FOR(i, 1, n)
    {
        DFS(i, -1);
        Sub(f[i], 1);
        cout << f[i] << '\n';
    }

    return 0;
}
