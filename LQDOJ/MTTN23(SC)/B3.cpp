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
int const LOG = 19;
long long const oo = 1e18;

int n, m, q;
vector<pair<int, int>> adj[N];
int st[N], ed[N], t[N], s[N];

int h[N];
long long d[N];

int up[2 * N][22];
int pos[N];
int timer = 0;

void DFS(int u, int p)
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
        DFS(v, u);
        up[++timer][0] = u;
    }
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

bool Inter(int &u, int &v, int &p)
{
    return (LCA(u, p) ^ LCA(v, p) ^ LCA(u, v)) == p;
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

    h[0] = -1;
    DFS(1, -1);
    Build();

    FOR(i, 1, m) cin >> st[i] >> ed[i] >> t[i] >> s[i];

    while (q--)
    {
        int u; cin >> u;

        double res = oo;
        FOR(i, 1, m) if (Inter(st[i], ed[i], u))
            mini(res, t[i] + (double)(d[st[i]] + d[u] - 2 * d[LCA(st[i], u)]) / s[i]);

        if (res == oo) cout << "-1\n";
        else cout << fixed << setprecision(6) << res << '\n';
    }

    return 0;
}