#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

#define name "QKGRAPH"

int const N = 1e5 + 5;

int n;
int q;

vector<Edge> adj[N];
bool visited[N];

void BFS(int &s, int &k)
{
    queue<int> qu;
    qu.push(s);

    visited[s] = true;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto e : adj[u])
        {
            int v = e.v;
            int w = e.w;

            if (visited[v]) continue;
            if (w >= k)
            {
                visited[v] = true;
                qu.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    while (q--)
    {
        int k, v;
        cin >> k >> v;

        memset(visited, 0, sizeof visited);
        BFS(v, k);
        int res = 0;

        for (int u = 1; u <= n; u++) if (visited[u]) res++;
        cout << res - 1 << '\n';
    }

    return 0;
}