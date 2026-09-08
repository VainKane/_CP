#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
};

#define name "twotrees"

int const N = 4009;

int n;

vector<int> adj[3][N];

int par[3][N];
int child[3][N];
int cnt[N][N];

bool mark[N];
int res[N];

Edge a[3][N];

void DFS(int id, int u)
{
    child[id][u] = 1;

    for (auto v : adj[id][u])
    {
        if (v == par[id][u]) continue;
        
        par[id][v] = u;
        DFS(id, v);
        child[id][u] += child[id][v];
    }
}

void DFSMark(int u)
{
    mark[u] = true;
    for (auto v : adj[2][u])
    {
        if (v == par[2][u]) continue;
        DFSMark(v);
    }
}

void DFSCnt(int u, int x)
{
    cnt[u][x] = mark[u];
    for (auto v : adj[1][u])
    {
        if (v == par[1][u]) continue;
        DFSCnt(v, x);
        cnt[u][x] += cnt[v][x];
    }
}

void Init()
{
    DFS(1, 1);
    DFS(2, 1);

    for (int u = 1; u <= n; u++)
    {
        memset(mark, 0, sizeof mark);
        DFSMark(u);
        DFSCnt(1, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;

    for (int id = 1; id <= 2; id++)
    {
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[id][u].push_back(v);
            adj[id][v].push_back(u);

            a[id][i] = {u, v};
        }
    }

    Init();

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int val = 0;

            int a1 = a[1][i].u;
            int b1 = a[1][i].v;
            int a2 = a[2][j].u;
            int b2 = a[2][j].v;

            if (par[1][a1] != b1) swap(a1, b1);
            if (par[2][a2] != b2) swap(a2, b2);

            int x = child[1][a1];
            int y = child[2][a2];
            int k = cnt[a1][a2];

            val = max({val, k, x - k, y - k, n - x - y + k});

            res[val]++;
        }
    }

    for (int i = 0; i <= n; i++) cout << res[i] << ' ';

    return 0;
}