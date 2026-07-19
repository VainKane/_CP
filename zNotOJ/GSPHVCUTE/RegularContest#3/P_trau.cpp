#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "business"

int const N = 3e5 + 5;

int n, k;
vector<int> adj[N];

int d[N];
bool visited[N];

vector<int> nodes;

int maxD;

void BFS(int s)
{
    memset(visited, false, sizeof visited);
    queue<int> q;

    for (auto v : nodes) 
    {
        visited[v] = true;
        d[v] = 0;
        q.push(v);
    }

    visited[s] = true;
    d[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) if (!visited[v])
        {
            visited[v] = true;
            d[v] = d[u] + 1;
            q.push(v);

            maxD = max(maxD, d[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, k) 
    {
        int p; cin >> p;
        nodes.push_back(p);
    }
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 1e9;
    FOR(u, 1, n)
    {
        maxD = 0;
        BFS(u);
        res = min(res, maxD);

        // cout << u << ' ' << maxD << '\n';
    }

    cout << res;

    return 0;
}