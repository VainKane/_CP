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

int const N = 1e5 + 5;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }
};

int n, l, c;
vector<ii> adj[N];

int sz[N];
bool del[N];

int h[N], d[N];

int in[N], out[N];
int node[N];
int timer = 0;

FenwickTree bit;

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p || del[v]) continue;

        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

int Centroid(int u, int p, int n)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p && del[v] && sz[v] <= n / 2) continue;
        return Centroid(v, u, n);
    }
    
    return u;
}

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;

    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p || del[v]) continue;

        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFS(v, u);
    }

    out[u] = timer;
}

void Solve(int u)
{
    DFSPrepare(u, -1);
    int cen = Centroid(u, -1, sz[u]);

    del[cen] = true;
    h[cen] = d[cen] = timer = 0;

    for (auto &e : adj[cen])
    {
        int v = e.F;
        if (del[v]) continue;

        vector<int> nodes;
        FOR(i, in[v], out[v]) nodes.push_back(node[i]);
        sort(all(nodes), cmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> c;
    FOR(i, 2, n)
    {
        int p, w;
        cin >> p >> w;
        adj[i].push_back({p, w});
        adj[p].push_back({i, w});
    }

    bit = FenwickTree(n);
    Solve(1);

    return 0;
}