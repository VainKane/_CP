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
#define name "SHIP"

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

int n, k;

int a[N];
vector<int> adj[N];

int h[N];
int par[N];

long long f[N];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        par[v] = u;
        DFS(v, u);
    }
}

int GetMax(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int res = max(a[u], a[v]);

    while (h[u] > h[v])
    {
        maxi(res, max(a[u], a[par[u]]));
        u = par[u];
    }

    if (u == v) return res;

    while (u != v)
    {
        maxi(res, max(a[u], a[v]));
        u = par[u];
        v = par[v];
    }

    return max(res, a[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    h[0] = -1;
    DFS(1, -1);

    memset(f, -0x3f, sizeof f);
    f[1] = 0;

    cin >> k;
    FOR(i, 1, k)
    {
        int u, v;
        cin >> u >> v;

        maxi(f[v], f[u] + GetMax(u, v));
    }

    long long res = 0;
    FOR(u, 1, n) maxi(res, f[u]);
    cout << res;

    return 0;
}
