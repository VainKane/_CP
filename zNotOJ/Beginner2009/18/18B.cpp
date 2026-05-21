#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;

int n;
int m;

vector<int> adj[N];
int trace[N];

int res = 0;

void BFS(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (!trace[v])
            {
                trace[v] = u;
                q.push(v);
            }
        }
    }
}

void DFS(int u)
{
    for (auto v : adj[u])
    {
        if (!trace[v])
        {
            trace[v] = u;
            DFS(v);
        }
    }
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

    for (int i = 1; i <= n; i++)
    {
        if (!trace[i])
        {
            DFS(i);
            res++;
        }
    }

    cout << res;

    return 0;
}