#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 105;

int n, m;
vector<int> adj[N];

int id[N], low[N];
int f[N];

int timer = 0;
int res = 0;

void Tarjan(int u, int p)
{
    low[u] = id[u] = ++timer;
    f[u] = 1;

    for (auto &v : adj[u]) if (v != p)
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v, u);
            
            low[u] = min(low[u], low[v]);
            f[u] += f[v];

            if (low[v] == id[v]) res += f[v] * (n - f[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(u, 1, n) if (!id[u]) Tarjan(u, -1);
    cout << res;

    return 0;
}