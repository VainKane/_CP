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
#define name "bridge"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const LOG = 20;

int n, m, q;

ii edges[N];

vector<ii> adj[N];
vector<int> bridgeAdj[N];

int in[N], low[N];
int ccId[N];
int timer = 0, cc = 0;

bool bridge[N];

int pos[N], h[N];
int up[LOG][2 * N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    for (auto &e : adj[u])
    {
        int v = e.F, i = e.S;

        if (v == p || ccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);

            if (low[v] == in[v]) bridge[i] = edges[i - 1] != edges[i] && edges[i] != edges[i + 1];
        }
    }
}

void DFS(int u)
{
    ccId[u] = cc;
    for (auto &e : adj[u])
    {
        int v = e.F, i = e.S;
        if (!ccId[v] && !bridge[i]) DFS(v);
    }
}

bool cmp(int u, int v) { return h[u] < h[v]; }

void DFSPrepare(int u, int p)
{
    up[0][++timer] = u;
    pos[u] = timer;

    for (auto &v : bridgeAdj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);
        up[0][++timer] = u;
    }
}

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[j][i] = min(up[j - 1][i], up[j - 1][i + MK(j - 1)], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[k][u], up[k][v - MK(k) + 1], cmp);
}

int Dist(int u, int v) { return h[u] + h[v] - 2 * h[LCA(u, v)]; }
bool Check(int p, int u, int v) { return Dist(p, u) + Dist(p, v) == Dist(u, v); }

int Inter(int p, int u, int q, int v)
{
    int a = max(p, q, cmp), b = LCA(u, v);
    int c = a ^ p ^ q;

    if (Check(a, p, u) && Check(b, p, u) && Check(a, c, v) && Check(b, c, v)) return h[b] - h[a];
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {min(u, v), max(u, v)};
    }

    sort(edges + 1, edges + m + 1);
    FOR(i, 1, m)
    {
        int u = edges[i].F, v = edges[i].S;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    Tarjan(1, -1);
    FOR(u, 1, n) if (!ccId[u]) cc++, DFS(u);

    FOR(i, 1, m) if (bridge[i])
    {
        int u = ccId[edges[i].F], v = ccId[edges[i].S];
        bridgeAdj[u].push_back(v);
        bridgeAdj[v].push_back(u);
    }

    timer = 0;
    DFSPrepare(1, -1);
    Build();

    while (q--)
    {
        int a, b, u, v;
        cin >> a >> b >> u >> v;

        a = ccId[a], b = ccId[b], u = ccId[u], v = ccId[v];
        int p = LCA(a, b), q = LCA(u, v);

        cout << Dist(u, v) - Inter(p, a, q, u) - Inter(p, a, q, v) - Inter(p, b, q, u) - Inter(p, b, q, v) << '\n';
    }

    return 0;
}