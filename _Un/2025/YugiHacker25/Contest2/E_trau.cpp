#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 2e5 + 5;

int n, m;
vector<int> adj[N];

int cnt[N];

int par[N];
int h[N];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        par[v] = u;
        DFS(v, u);
    }
}

void Update(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    FOR(i, 1, delta) 
    {
        cnt[u]++;
        u = par[u];
    }

    while (u != v)
    {
        cnt[u]++;
        cnt[v]++;

        u = par[u];
        v = par[v];
    }
    cnt[u]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Update(u, v);
    }

    FOR(u, 1, n) cout << cnt[u] << ' ';

    return 0;
}