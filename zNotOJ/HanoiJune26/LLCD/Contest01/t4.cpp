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

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }

    int Get(int l, int r)
    {
        maxi(l, 1), mini(r, n);
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int n, l, r;

int v[N], d[N];
vector<int> adj[N];

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

set<int> s[N];
FenwickTree bit;

ll cur = 0;
ll res[N];

void DFSPrepare(int u, int p)
{
    s[u] = {v[u]};
    in[u] = ++timer;
    node[timer] = u;
    int sz = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);

        if (maxi(sz, out[v] - in[v] + 1)) bigChild[u] = v;
        if (sz(s[u]) < sz(s[v])) swap(s[u], s[v]);
        s[u].insert(all(s[v]));
    }

    d[u] = sz(s[u]);
    out[u] = timer;
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        DFS(v, u);
        FOR(i, in[v], out[v]) bit.Update(d[node[i]], -1);
    }

    cur = 0;
    if (bigChild[u]) DFS(bigChild[u], u);
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        FOR(i, in[v], out[v])
        {
            int x = d[node[i]];
            cur += bit.Get(x - r, x - l) + bit.Get(l + x, r + x);
        }

        FOR(i, in[v], out[v]) bit.Update(d[node[i]], 1);
    }

    bit.Update(d[u], 1);
    cur += bit.Get(d[u] - r, d[u] - l) + bit.Get(l + d[u], r + d[u]);
    res[u] = cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;
    FOR(i, 1, n) cin >> v[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bit = FenwickTree(n);
    DFSPrepare(1, -1);
    DFS(1, -1);

    FOR(u, 1, n) cout << res[u] << ' ';

    return 0;
}