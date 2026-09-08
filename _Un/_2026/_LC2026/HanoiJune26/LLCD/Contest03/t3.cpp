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

int const N = 2e5 + 5;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        if (++idx < 1) return;
        mini(idx, n);
        for (; idx; idx ^= idx & -idx) bit[idx] += val;
    }

    int Get(int idx)
    {
        idx++;

        int res = 0;
        for (; idx <= n; idx += idx & -idx) res += bit[idx];
        return res;
    }
};

int n;

int c[N];
vector<int> adj[N];

bool del[N];
int sz[N];

int in[N], out[N];
int node[N];
int timer = 0;

int h[N], cnt[N];
int res[N];

FenwickTree bit;

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

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;

    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        h[v] = h[u] + 1;
        DFS(v, u);
    }

    out[u] = timer;
}

void Update(vector<int> &child)
{
    for (auto &v : child)
    {
        FOR(i, in[v], out[v]) res[node[i]] += bit.Get(h[node[i]]);
        FOR(i, in[v], out[v]) bit.Update(c[node[i]] - h[node[i]], 1);
    }
}

void Solve(int u)
{
    DFSPrepare(u, -1);
    int cen = Centroid(u, -1, sz[u]);

    del[cen] = true;
    h[cen] = timer = 0;

    DFS(cen, -1);

    vector<int> child;
    for (auto &v : adj[cen]) if (!del[v]) child.push_back(v);

    Update(child);
    reverse(all(child));

    res[cen] += bit.Get(h[cen]);
    for (auto &v : child) FOR(i, in[v], out[v]) bit.Update(c[node[i]] - h[node[i]], -1);
    
    bit.Update(c[cen] - h[cen], 1);
    Update(child);

    FOR(i, in[cen], out[cen]) bit.Update(c[node[i]] - h[node[i]], -1);
    for (auto &v : child) Solve(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bit = FenwickTree(n);
    Solve(1);
    
    FOR(u, 1, n) cout << res[u] << ' ';

    return 0;
}