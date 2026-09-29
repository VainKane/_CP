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

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int n, q;

int c[N];
vector<int> adj[N];

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

vector<ii> qr[N];
int res[N];

FenwickTree bit;
int cnt[N];

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    int sz = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        if (maxi(sz, out[v] - in[v] + 1)) bigChild[u] = v;
    }

    out[u] = timer;
}

void Add(int &val, int delta)
{
    if (val) bit.Update(val, -1);
    val += delta;
    if (val) bit.Update(val, 1);
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        DFS(v, u);
        FOR(i, in[v], out[v]) Add(cnt[c[node[i]]], -1);
    }

    if (bigChild[u]) DFS(bigChild[u], u);
    for (auto &v : adj[u]) if (v != p && v != bigChild[u]) FOR(i, in[v], out[v])
        Add(cnt[c[node[i]]], 1);

    Add(cnt[c[u]], 1);
    for (auto &qp : qr[u]) res[qp.S] = bit.Get(qp.F, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, q)
    {
        int v, k;
        cin >> v >> k;
        qr[v].push_back({k, i});
    }

    bit = FenwickTree(n);
    DFSPrepare(1, -1);
    DFS(1, -1);

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}