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

int const N = 8e4 + 5;
int const M = 2e4 + 5;
ll const oo = 1e18 + 67;

struct Data
{
    int w, t, p;

    Data(int _w = 0, int _t = 0, int _p = 0) { w = _w, t = _t, p = _p; }
    void Input() { cin >> w >> t >> p; }
    bool operator < (Data const other) const { return t < other.t; }
};

struct FenwickTree
{
    vector<ll> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, -oo);
    }

    void Update(int idx, ll val) { for (; idx <= n; idx += idx & -idx) maxi(bit[idx], val); }
    
    ll Get(int idx)
    {
        ll res = -oo;
        for (; idx; idx ^= idx & -idx) maxi(res, bit[idx]);
        return res;
    }
};

int n, m, bullshit;

vector<int> adj[N];
vector<ii> cenAdj[N];

Data a[M];

bool del[N];
int sz[N];
int timer = 0;

vector<int> t[N];
FenwickTree bit[N];
vector<int> vals[N];

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

int Centroid(int u, int p, int n)
{
    for (auto &v : adj[u]) if (v != p && !del[v] && sz[v] > n / 2) return Centroid(v, u, n);
    return u;
}

void DFS(int u, int p, int &cen, int h = 0)
{
    for (auto &ti : t[u]) vals[cen].push_back(h + ti);
    cenAdj[u].push_back({cen, h});
    for (auto &v : adj[u]) if (v != p && !del[v]) DFS(v, u, cen, h + 1);
}

void Solve(int u)
{
    DFSPrepare(u, -1);
    int cen = Centroid(u, -1, sz[u]);

    del[cen] = true;
    DFS(cen, -1, ++timer);

    for (auto &v : adj[cen]) if (!del[v]) Solve(v);
}

void Compress(int id)
{
    sort(all(vals[id]));
    vals[id].erase(unique(all(vals[id])), vals[id].end());
    bit[id] = FenwickTree(sz(vals[id]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> bullshit;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, m) a[i].Input();

    FOR(i, 1, m) t[a[i].w].push_back(a[i].t);
    t[1].push_back(0);
    sort(a + 1, a + m + 1);
    
    Solve(1);
    FOR(i, 1, timer) Compress(i);

    for (auto &p : cenAdj[1])
    {
        int id = p.F, h = p.S;
        bit[id].Update(lower_bound(all(vals[id]), h) - vals[id].begin() + 1, 0);
    }

    ll res = 0;
    FOR(i, 1, m)
    {
        int u = a[i].w;
        ll dp = -oo;

        for (auto &p : cenAdj[u])
        {
            int id = p.F, h = p.S;
            maxi(dp, bit[id].Get(upper_bound(all(vals[id]), a[i].t - h) - vals[id].begin()) + a[i].p);
        }

        for (auto &p : cenAdj[u])
        {
            int id = p.F, h = p.S;
            bit[id].Update(lower_bound(all(vals[id]), a[i].t + h) - vals[id].begin() + 1, dp);
        }

        maxi(res, dp);
    }

    cout << res;

    return 0;
}