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
int const LOG = 20;
int const MOD = 1e9 + 7;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

struct DSU
{
    vector<int> par, sz;
    vector<int> l, r;
    int n, res;
    
    void MakeSet()
    {
        res = 1;
        FOR(i, 1, n)
        {
            par[i] = i, sz[i] = 1;
            res = 1LL * res * (r[i] - l[i] + 1) % MOD;
        }
    }

    DSU(int _n = 0, int _l[] = {}, int _r[] = {})
    {
        n = _n;
        par = sz = l = r = vector<int>(n + 5, 0);
        FOR(i, 1, n) l[i] = _l[i], r[i] = _r[i];
        MakeSet();
    }

    int Find(int v) { return par[v] == v ? par[v] : Find(par[v]); }
    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        assert(r[a] - l[a] + 1 > 0);
        assert(r[b] - l[b] + 1 > 0);

        res = 1LL * res * PowMod(max(r[a] - l[a] + 1, 0), MOD - 2) % MOD;
        res = 1LL * res * PowMod(max(r[b] - l[b] + 1, 0), MOD - 2) % MOD;
        
        maxi(l[a], l[b]), mini(r[a], r[b]);
        res = 1LL * res * max(r[a] - l[a] + 1, 0) % MOD;

        sz[a] += sz[b];
        par[b] = a;

        return true;
    }
};

int n;

vector<int> adj[N];
int l[N], r[N];

int h[N];
int up[N][LOG];
DSU st[LOG];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, 31 - __builtin_clz(n)) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, 31 - __builtin_clz(n), 0) if (h[up[u][i]] >= h[v])
        u = up[u][i];

    if (u == v) return u;

    FORD(i, 31 - __builtin_clz(n), 0) if (up[u][i] != up[v][i])
        u = up[u][i], v = up[v][i];

    return up[u][0];
}

int Kth(int u, int k, int v = 0)
{
    if (v) return Kth(v, h[v] - h[u] - k);

    for (int tmp = k; tmp; tmp ^= tmp & -tmp)
        u = up[u][__builtin_ctz(tmp)];
    
    return u;
}

void Union(int u, int edU, int v, int edV, int k)
{
    if (!u || !v) return;
    if (st[k].Union(u, v) || !k) return;

    Union(u, edU, v, edV, k - 1);
    Union(Kth(u, k - 1, edU), edU, Kth(v, k - 1, edV), edV, k - 1);
}

void Update(int u, int edU, int v, int edV, int len)
{
    for (int tmp = len; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        Union(u, edU, v, edV, i);
        u = Kth(u, i, edU), v = Kth(v, i, edV);
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    FOR(i, 1, n) cin >> l[i] >> r[i];

    h[0] = -1;
    DFS(1, -1);

    FOR(i, 0, 31 - __builtin_clz(n)) st[i] = DSU(n, l, r);

    int q; cin >> q;
    while (q--)
    {
        int u1, v1, u2, v2;
        cin >> u1 >> v1 >> u2 >> v2;

        int p1 = LCA(u1, v1), p2 = LCA(u2, v2);
        if (h[u1] - h[p1] > h[u2] - h[p2]) swap(u1, u2), swap(v1, v2), swap(p1, p2);

        int len = h[u2] - h[p2] - (h[u1] - h[p1]);
        int k1 = Kth(v1, h[v1] - h[p1] - len);
        int k2 = Kth(u2, h[u1] - h[p1]);
    
        Update(u1, 0, u2, 0, h[u1] - h[p1] + 1);
        Update(p1, k1, k2, 0, len + 1);
        Update(k1, v1, p2, v2, h[v2] - h[p2] + 1);

        cout << st[0].res << '\n';
    }

    return 0;
}