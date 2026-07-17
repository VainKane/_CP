#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const oo = 1e9;
int const LOG = 17;

int n;
vector<pair<int, int>> adj[N];

int h[N];
int upPar[N][20];
int upMin[N][20];
int upMax[N][20];

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        h[v] = h[u] + 1;
        upPar[v][0] = u;
        upMin[v][0] = upMax[v][0] = w;

        FOR(i, 1, LOG) 
        {
            upPar[v][i] = upPar[upPar[v][i - 1]][i - 1];
            upMin[v][i] = min(upMin[v][i - 1], upMin[upPar[v][i - 1]][i - 1]);
            upMax[v][i] = max(upMax[v][i - 1], upMax[upPar[v][i - 1]][i - 1]);
        }
        
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        u = upPar[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (upPar[u][i] != upPar[v][i])
    {
        u = upPar[u][i];
        v = upPar[v][i];
    }

    return upPar[u][0];
}

int GetMin(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    if (u == v) return oo;

    int res = upMin[u][0];
    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        mini(res, upMin[u][i]);
        u = upPar[u][i];
    }

    return res;
}

int GetMax(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    if (u == v) return 0;

    int res = upMax[u][0];
    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        maxi(res, upMax[u][i]);
        u = upPar[u][i];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1);
    
    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int p = LCA(u, v);
        cout << min(GetMin(u, p), GetMin(v, p)) << ' ';
        cout << max(GetMax(u, p), GetMax(v, p)) << '\n';
    }

    return 0;
}