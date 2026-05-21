#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;

int n;
int m;
int s;
int t;

vector<int> adj[N];
int par[N];
bool visisted[N];

vector<int> res;

void DFS(int u)
{
    visisted[u] = true;

    for (auto v : adj[u])
    {
        // if (v == par[u]) continue;
        if (visisted[v]) continue;

        par[v] = u;
        DFS(v);
    }
}

void BFS(int s)
{
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (!par[v])
            {
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(s);
    int pos = t;
    while (pos != s && pos != 0)
    {
        res.push_back(pos);
        pos = par[pos];
    }
    res.push_back(s);

    if (!par[t])
    {
        cout << -1;
        return 0;
    }

    cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << ' ';
    }

    return 0;
}