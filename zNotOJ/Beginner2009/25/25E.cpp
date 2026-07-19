#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;
int const LOG = 17;

int n, m;
int s, t;

vector<int> adj[N];

int h[N];
int par[N];

int up[N][LOG + 5];
int upMin[N][LOG + 5];

vector<int> res;

void Build()
{
    queue<int> qu;
    qu.push(s);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u]) if (h[v] == -1)
        {
            h[v] = h[u] + 1;
            qu.push(v);
        }
    }
}

bool Better(int u, int v)
{
    int uMin = u;
    int vMin = v;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            uMin = min(uMin, upMin[u][i]);
            vMin = min(vMin, upMin[v][i]);

            u = up[u][i];
            v = up[v][i];
        }
    }

    return uMin < vMin;
}

void BFS()
{
    if (h[t] == -1)
    {
        cout << -1;
        exit(0);
    }

    queue<int> qu;
    qu.push(s);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u]) if (h[v] == h[u] - 1)
        {
            if (Better(v, par[u])) par[u] = v;
        }
        
        up[u][0] = par[u];
        upMin[u][0] = min(u, par[u]);

        FOR(i, 1, LOG)
        {
            int p = up[u][i - 1];
            up[u][i] = up[p][i - 1];
            upMin[u][i] = min(upMin[u][i - 1], upMin[p][i - 1]);
        }

        for (auto v : adj[u]) if (h[v] == h[u] + 1 && !par[v]) 
        {
            par[v] = u;
            qu.push(v);
        }
    }
}

void Init()
{
    memset(h, -1, sizeof h);
    h[s] = 0;

    Build();
    BFS();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Init();

    res.push_back(t);
    while (par[t]) res.push_back(t = par[t]);
    reverse(all(res));

    for (auto v : res) cout << v << ' ';

    return 0;
}