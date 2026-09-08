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

int const N = 2e3 + 5;
int const LOG = 19;
long long const oo = 1e18;

int n, m, q;

int st[N], ed[N], t[N], s[N];
vector<pair<int, int>> adj[N];

vector<int> stId[N], edId[N];
vector<int> stS[N], edS[N];
long long f[N];

int up[2 * N][22];

long long d[N];
int h[N];

int pos[N], out[N];
int timer = 0;

void DFSPrepare(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFSPrepare(v, u);
        up[++timer][0] = u;
    }

    out[u] = timer;
}

bool cmp(int u, int v)
{
    return h[u] < h[v];
}

void Build()
{
    FOR(j, 1, LOG) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

long long Dist(int u, int v)
{
    return d[u] + d[v] - 2 * d[LCA(u, v)];
}

bool Inside(int child, int par)
{
    return pos[par] <= pos[child] && out[par] >= out[child];
}

void Merge(int u, int v, vector<int> set[], int des[])
{
    // if (sz(set[u]) < sz(set[v])) swap(set[u], set[v]);
    for (auto &i : set[v])
    {
        if (!Inside(des[i], v)) mini(f[u], 1LL * t[i] * s[1] + Dist(st[i], u));
        set[u].push_back(i);
    }
}

void DFS(int u, int p)
{
    f[u] = oo;
    for (auto &i : stId[u])
    {
        mini(f[u], 1LL * t[i] * s[1]);
        stS[u].push_back(i);
    }

    for (auto &i : edId[u])
    {
        mini(f[u], 1LL * t[i] * s[1] + Dist(st[i], u));
        edS[u].push_back(i);
    }

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;

        DFS(v, u);
        Merge(u, v, stS, ed);
        Merge(u, v, edS, st);
    }
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

    FOR(i, 1, m) 
    {
        cin >> st[i] >> ed[i] >> t[i] >> s[i];
        stId[st[i]].push_back(i);
        edId[ed[i]].push_back(i);
    }

    DFSPrepare(1, -1);
    Build();

    DFS(1, -1);

    while (q--)
    {
        int u; cin >> u;
        if (f[u] == oo) cout << "-1\n";
        else cout << fixed << setprecision(6) << (double)f[u] / s[1] << '\n';
    }

    return 0;
}