#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "TRAVEL"

struct Edge
{
    int u, v, c1, c2;

    int Other (int p) const
    {
        return (u ^ v ^ p);
    }
};

int const N = 2e5 + 5;

int n;
vector<int> adj[N];
Edge edges[N];

int par[N];
int cnt[N];

void DFS(int u)
{
    for (auto i : adj[u]) if (i != par[u])
    {
        int v = edges[i].Other(u);
        par[v] = i;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n - 1)
    {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        
        edges[i] = {u, v, c1, c2};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    FOR(u, 1, n - 1)
    {
        par[u] = -1;
        DFS(u);

        int v = u + 1;
        // vector<int> path;
        while (par[v] != -1)
        {
            // path.push_back(par[v]);
            cnt[par[v]]++;
            v = edges[par[v]].Other(v);
        }
        // cout << "From " << u << " to " << u + 1 << ": ";
        // for (auto v : path) cout << v << ' ';
        // cout << '\n';
    }

    long long res = 0;
    FOR(i, 1, n - 1) res += min(1ll * edges[i].c1 * cnt[i], 1ll * edges[i].c2);

    cout << res;

    return 0;
}