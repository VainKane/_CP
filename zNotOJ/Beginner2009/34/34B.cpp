#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

vector<int> adj[N];

int par[N];
int id[N];
int low[N];

int cnt = 0;

int cc = 0;
int bridges;
int nodes[N];
int vertiecs[3];

long long s2 = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    nodes[u]++;
    vertiecs[cc]++;

    for (auto v : adj[u])
    {   
        if (v == par[u]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            nodes[u] += nodes[v];

            if (low[v] == id[v])
            {
                bridges++;
                s2 += 1ll * (n- nodes[v]) * nodes[v] - 1;
            }
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
        if (!id[i])
        {
            cc++;
            DFS(i);
            if (cc > 2)
            {
                cout << 0;
                exit(0);
            }
        }
    }

    if (cc == 1)
    {
        long long s1 = (m - bridges) * ( (n * (n - 1ll)) / 2 - m);
        cout << s1 + s2;
    }
    else cout << (m - bridges) * 1ll * vertiecs[1] * vertiecs[2];

    return 0;
}