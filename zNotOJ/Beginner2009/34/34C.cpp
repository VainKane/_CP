#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;
int q;

vector<int> adj[N];

int low[N];
int id[N];
int par[N];
int out[N];

int up[N][LOG + 5];
int h[N];

bool cut[N];
int cnt = 0;

int Find(int u, int par) 
{
    for (int i = LOG; i >= 0; i--)
    {
        if (h[up[u][i]] > h[par])
        {
            u = up[u][i];
        }
    }

    return u;
}

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    int child = (par[u] != 0);

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            up[v][0] = u;
            h[v] = h[u] + 1;
            DFS(v);
            low[u] = min(low[u], low[v]);

            if (low[v] >= id[u])
            {
                child++;
            }
        }
    }

    if (child >= 2)
    {
        cut[u] = true;
    }

    out[u] = cnt;
}

bool child(int v, int u)
{
    return id[u] <= id[v] && id[v] <= out[u];
}

bool Query1(int a, int b, int c, int d)
{
    if (id[c] > id[d]) swap(c, d);
    if (low[d] != id[d]) return true;
    return (child(a, d) == child(b, d));
}

bool Query2(int a, int b, int c) 
{
    if (!cut[c]) return true;
    int pa = 0, pb = 0;
    if (child(a, c)) pa = Find(a, c);
    if (child(b, c)) pb = Find(b, c);

    if (pa == pb) return true;
    if (!pa && low[pb] < id[c]) return true;
    if (!pb && low[pa] < id[c]) return true;
    if (pa && pb && low[pa] < id[c] && low[pb] < id[c]) return true;

    return false;
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

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);
   
    // for (int u = 1; u <= n; u++)
    // {
    //     for (int i = 1; i <= LOG; i++)
    //     {
    //         up[u][i] = up[up[u][i - 1]][i - 1];
    //     }
    // }

    for (int i = 1; i <= LOG; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }

    cin >> q;

    while (q--)
    {
        int type, a, b, c, d;
        cin >> type;

        if (type == 1)
        {
            cin >> a >> b >> c >> d;
            cout << (Query1(a, b, c, d) ? "yes\n" : "no\n");
        }
        else
        {
            cin >> a >> b >> c;
            cout << (Query2(a, b, c) ? "yes\n" : "no\n");
        }

        // cout << cut[6];
    }

    return 0;
}