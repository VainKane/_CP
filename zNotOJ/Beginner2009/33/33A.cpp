#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

vector<int> adj[N];
int id[N];
int par[N];
int low[N];

vector<pair<int, int>> res;

int cnt = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);

            if (low[v] == id[v]) res.push_back({min(u, v), max(u, v)});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!id[i]) DFS(i);
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto val : res) cout << val.first << ' ' << val.second << '\n';

    return 0;
}