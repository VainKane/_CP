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
long long const oo = 1e18;

int n, m, q;
vector<pair<int, int>> adj[N];

int h[N];
long long d[N];

int up[N][20];
double res[N];

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        up[v][0] = u;

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

void Update(int u, int v, int t, int s)
{
    int p = LCA(u, v);

    int node = u;
    while (node != p)
    {
        long long dist = d[u] + d[node] - 2 * d[node];
        mini(res[node], t + (double)dist / s);
        node = up[node][0];
    }

    node = v;
    while (node != p)
    {
        long long dist = d[u] + d[node] - 2 * d[p];
        mini(res[node], t + (double)dist / s);
        node = up[node][0];
    }

    mini(res[p], t + (double)(d[u] - d[p]) / s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
   
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(u, 1, n) res[u] = oo;
    h[0] = -1;
    DFS(1, -1);

    FOR(i, 1, m)
    {
        int u, v, s, t;
        cin >> u >> v >> t >> s;
        Update(u, v, t, s);
    }

    while (q--)
    {
        int u; cin >> u;
        if (res[u] == oo) cout << "-1\n";
        else cout << fixed << setprecision(6) << res[u] << '\n';
    }

    return 0;
}