#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e4 + 5;

int n, m;
vector<int> adj[N];

int id[N], low[N];
int timer = 0;

int bridges = 0, joints = 0;

void Tarjan(int u, int p)
{
    int child = (p != -1);
    id[u] = low[u] = ++timer;

    for (auto &v : adj[u]) if (v != p)
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v, u);

            low[u] = min(low[u], low[v]);
            if (low[v] == id[v]) bridges++;
            if (low[v] >= id[u]) child++;
        }
    }

    joints += child >= 2;
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
    cout << joints << ' ' << bridges;

    return 0;
}