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

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e4 + 5;
long long const oo = 3e9;

ll Ceil(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    ll x, a, b;

    Segment(ll _x = 0, ll _a = 0, ll _b = 0)
    {
        x = _x, a = _a, b = _b;
    }

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }

    ll Val()
    {
        return x * a + b;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;

    void Add(ll a, ll b)
    {
        while (!seg.empty() && seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({0, a, b});
        else if (seg.back().a != a)
        {
            long long x = Ceil(b - seg.back().b, seg.back().a - a);
            maxi(x, 0LL), mini(x, oo);
            seg.push_back({x, a, b});
        }
    }

    ll Get(ll x)
    {
        int id = upper_bound(all(seg), Segment(x)) - seg.begin() - 1;
        return x * seg[id].a + seg[id].b;
    }
};

int n, m;
vector<int> adj[N];

int sz[N];
ll f[N], fPar[N];
ll g[N], gPar[N];

ConvexHullTrick cht;

void DFSPrepare(int u, int p)
{
    f[u] = g[u] = 0;
    sz[u] = 1;

    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);

        sz[u] += sz[v];
        f[u] += f[v] + sz[v];
        g[u] += sz[v] + 2 * f[v] + g[v];
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        ll tmp = f[u] + fPar[u] - f[v] - sz[v];
        fPar[v] = tmp + sz[1] - sz[v];
        gPar[v] = fPar[v] + tmp + g[u] + gPar[u] - sz[v] - 2 * f[v] - g[v];

        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    cin >> m;
    FOR(u, 1, m) adj[u].clear();
    FOR(i, 2, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll cost1 = 0, cost2 = 0, cost = 7e18;
    vector<pair<ll, ll>> v;

    FOR(u, 1, n)
    {
        cost1 += g[u] + gPar[u];
        v.push_back({2 * (f[u] + fPar[u]), m * (g[u] + gPar[u])});
    }

    sort(all(v), greater<pair<ll, ll>> ());
    for (auto &p : v) cht.Add(p.F, p.S);

    DFSPrepare(1, -1);
    DFS(1, -1);

    FOR(u, 1, m)
    {
        cost2 += g[u] + gPar[u];
        ll y = f[u] + fPar[u] + m;
        mini(cost, cht.Get(y) + n * (g[u] + gPar[u] + 2 * (f[u] + fPar[u]) + m));
    }

    cout << cost + (cost1 + cost2) / 2;

    return 0;
}