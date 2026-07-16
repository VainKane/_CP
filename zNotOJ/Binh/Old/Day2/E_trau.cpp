#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n, m, q;

int colour[N], par[N];
vector<int> adj[N];

vector<int> nodes;
vector<int> c[N];

void DFS(int u)
{
    nodes.push_back(colour[u]);
    for (auto v : adj[u]) if (v != par[u]) 
    {
        par[v] = u;
        DFS(v);
    }
}

void Sub1()
{
    DFS(1);

    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int u; cin >> u;

            nodes.clear();
            DFS(u);

            sort(all(nodes));
            nodes.erase(unique(all(nodes)), nodes.end());
            
            cout << nodes.size() << '\n';
        }
        if (type == 2)
        {
            int u, k;
            cin >> u >> k;
            colour[u] = k;
        }
    }

    exit(0);
}

void DFS2(int u, int p)
{
    c[u].push_back(colour[u]);
    for (auto v : adj[u]) if (v != p)
    {
        DFS2(v, u);
        for (auto &x : c[v]) c[u].push_back(x);
    }

    sort(all(c[u]));
    c[u].erase(unique(all(c[u])), c[u].end());
}

void Sub2()
{
    DFS2(1, -1);
    while (q--)
    {
        int v; cin >> v >> v;
        cout << c[v].size() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> colour[i];
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (q <= 1000 && n <= 1000) Sub1();
    Sub2();

    return 0;
}