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

int const N = 1.5e5 + 5;
int const MOD = 998244353;

void Add(int x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] = (bit[idx] + val + MOD) % MOD; }
    
    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(l, val), Update(r + 1, -val);
    }

    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) Add(res, bit[idx]);
        return res;
    }
};

int n, q;
vector<int> adj[N];

int in[N], out[N];
int timer = 0;

int sz[N], bigChild[N];
int par[N], head[N];

int inv[N];

int sum[N];
FenwickTree bit;

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    int mx = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        par[v] = u;
        DFSPrepare(v, u);
        sz[u] += sz[v];
        if (maxi(mx, sz[v])) bigChild[u] = v;
    }
}

void DFS(int u, int p)
{
    in[u] = ++timer;
    if (bigChild[u])
    {
        head[bigChild[u]] = head[u];
        DFS(bigChild[u], u);
    }

    for (auto &v : adj[u]) if (v != p && v != bigChild[u]) DFS(v, u);
    out[u] = timer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    inv[1] = 1;
    FOR(i, 2, n) inv[i] = MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD;

    while (q--)
    {
        int type, u, d;
        cin >> type >> u;

        if (type == 1)
        {
            cin >> d;
            bit.Update(in[bigChild[u]], out[bigChild[u]], 1LL * d * inv[n - sz[bigChild[u]]] % MOD);

            int val = 1LL * d * (n - sz[u]) % MOD;
            bit.Update(1, in[u] - 1, val);
            bit.Update(out[u] + 1, n, val);

            Add(sum[u], d);
        }
        else
        {
        }
    }
    
    return 0;
}