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
#define name ""

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 526009;
int const LOG = 20;

int n;

int a[N];
vector<int> adj[N];

int h[N];
int up[N][22];

int node[N];

int in[N], out[N];
int timer = 0;

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
    out[u] = timer;
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);

    FORD(i, LOG, 0)
    {
        int p = up[u][i];
        if (p && h[p] >= h[v]) u = p;
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int Dist(int u, int v)
{
    return h[u] + h[v] - 2 * h[LCA(u, v)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    DFS(1, -1);

    long long res = 0;
    FOR(u, 1, n)
    {
        int s = 0;
        FOR(t, in[u], out[u]) s ^= (node[t] + Dist(u, node[t]));
        res += s;
    }

    cout << res;

    return 0;
}
