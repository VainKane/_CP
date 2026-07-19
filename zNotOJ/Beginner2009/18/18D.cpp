#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;

int n;
int k;
int m;

bool a[N];
int res[N];
vector<int> adj[N];
bool visisted[N];

int s;

void BFS()
{
    queue<int> qu;

    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            res[i] = 0;
            qu.push(i);
        }
    }

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        
        for (auto v : adj[u])
        {
            if (res[v] == 0 && !a[v])
            {
                visisted[v] = true;
                res[v] = res[u] + 1;
                qu.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int u;
        cin >> u;

        a[u] = true;
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS();
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}