#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "TENTROM"

int const N = 7e4 + 5;

int n;
vector<int> adj[N];

int deg[N];
int d[N], h[N];

int res = 0;

void BFS()
{
    memset(d, -1, sizeof d);
    queue<int> q;

    FOR(u, 1, n) if (deg[u] == 1) 
    {
        q.push(u);
        d[u] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) if (d[v] == -1)
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void DFS(int u, int p)
{
    for (auto v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        
        // if (h[v] >= d[v]) cout << v << ' ';
        if (h[v] >= d[v]) res++;
        else DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    
        deg[u]++, deg[v]++;
    }

    BFS();

    FOR(u, 1, n)
    {
        res = h[u] = 0;
        DFS(u, -1);
        cout << res << '\n';
    }

    return 0;
}