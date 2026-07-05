#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n;
vector<int> adj[N];

int f[N], s[N];

void DFS(int u, int p)
{
    s[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] += s[v] + f[v];
        s[u] += s[v];
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

    FOR(u, 1, n)
    {
        memset(f, 0, 4 * (n + 1));
        DFS(u, -1);
        cout << f[u] << ' ';
    }

    return 0;
}