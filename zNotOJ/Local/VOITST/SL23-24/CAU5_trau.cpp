#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "CAU5"

int const N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];

int f[N];

void DFS(int u, int p, int &x)
{
    f[u] = 1;
    for (auto &e : adj[u]) 
    {
        int v = e.F;
        int w = e.S;

        if (v == p || w > x) continue;

        DFS(v, u, x);
        f[u] += f[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    while (m--)
    {
        int q; cin >> q;
        long long res = 0;

        FOR(u, 1, n)
        {
            DFS(u, -1, q);
            res += f[u] - 1;
        }

        cout << res / 2 << '\n';
    }

    return 0;
}