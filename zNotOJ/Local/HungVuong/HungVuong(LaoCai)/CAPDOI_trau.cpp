#include <bits/stdc++.h>

using namespace std;

#define name "CAPDOI"

int const N = 1e5 + 5;

int n, k;
vector<int> adj[N];

bool used[N];

int in[N], out[N];
int cnt = 0;

void DFS(int u, int p)
{
    in[u] = ++cnt;
    for (auto v : adj[u]) if (v != p) DFS(v, u);
    out[u] = ++cnt;
}

bool isChild(int u, int v)
{
    return in[u] < in[v] && out[u] > out[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i < n; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        used[v] = true;
    }

    for (int u = 1; u <= n; u++) if (!used[u]) DFS(u, -1);

    long long res = 0;

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            res += (isChild(u, v) && abs(u - v) <= k);
        }
    }

    cout << res;
    cerr << res << '\n';

    return 0;
}