#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

vector<int> adj[N];
int par[N];
int id[N];
int low[N];

int val[N];
long long res[N];

int cnt = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    int child = (par[u] != 0);
    
    int sum = 0;
    val[u]++;

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;

        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);

            val[u] += val[v];

            if (low[v] >= id[u])
            {
                child++;
                sum += val[v];
                res[u] += 1ll * val[v] * (n - val[v]);
            }
        }
    }

    if (child >= 2)
    {
        res[u] += (n - 1ll - sum) * (1 + sum);
        res[u] += n - 1;
    }
    else res[u] = 2ll * (n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);
    for (int i = 1; i <= n; i++) cout << res[i] << '\n';

    return 0;
}