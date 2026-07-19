#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define name "Gannhat"

int const N = 5e5 + 5;

int n;
int m;
int bn;
int cn;

vector<int> adj[N];
int res[N];
int b[N];
int c[N];

bool visisted[N];

void BFS()
{
    queue<int> qu;
    for (int i = 1; i <= bn; i++)
    {
        qu.push(b[i]);
        visisted[b[i]] = true;
    }

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (visisted[v]) continue;

            visisted[v] = true;
            res[v] = res[u] + 1;
            qu.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> bn >> cn;

    for (int i = 1; i <= bn; i++) cin >> b[i];
    for (int i = 1; i <= cn; i++) cin >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    BFS();

    for (int i = 1; i <= cn; i++) cout << res[c[i]] << ' ';

    return 0;
}
