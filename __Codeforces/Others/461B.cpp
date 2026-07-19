#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];
bool colored[N];

int f[N][2];

void DFS(int u, int p)
{
    f[u][0] = !colored[u];
    f[u][1] = colored[u];

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        int x = (f[v][0] + f[v][1]) % MOD;
        f[u][1] = (1ll * f[u][1] * x + 1ll * f[u][0] * f[v][1]) % MOD;
        f[u][0] = 1ll * f[u][0] * x % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(++p);
        adj[p].push_back(i);
    }

    FOR(u, 1, n) cin >> colored[u];

    DFS(1, -1);
    cout << f[1][1];
    
    return 0;
}