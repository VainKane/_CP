#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
int const LOG = 18;

int n, k;
vector<pair<int, int>> adj[N];

int up[N][20];
int h[N], d[N];

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        up[v][0] = u;
        h[v] = h[u] + 1;
        d[v] = d[u] + w;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1);
    h[0] = -1;

    int res = n;

    FOR(u, 1, n) FOR(v, u + 1, n)
    {
        int p = LCA(u, v);
        if (d[u] + d[v] - 2 * d[p] == k) mini(res, h[u] + h[v] - 2 * h[p]);
    }

    if (res == n) res = -1;
    cout << res;

    return 0;
}