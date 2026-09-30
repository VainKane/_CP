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
    vector<vector<int>> bit, vals;
    int m, n;

    FenwickTree(int _m = 0, int _n = 0)
    {
        m = _m, n = _n;
        bit.assign(m + 5, vector<int>());
        vals.assign(m + 5, vector<int>());
    }

    void FakeUpdate(int i, int j)
    {
        for (; i <= m; i += i & -i) for (; j <= n; j += j & -j)
            vals[i].push_back(j);
    }

    void FakeGet(int i, int j)
    {
        for (; i; i ^= i & -i) for (; j; j ^= j & -j)
            vals[i].push_back(j);
    }

    void Compress()
    {
        FOR(i, 1, m)
        {
            sort(all(vals[i]));
            vals[i].erase(unique(all(vals[i])), vals[i].end());
            bit[i] = vector<int>(sz(vals[i]) + 5, 0);
        }
    }

    #define GetId(i, x) (lower_bound(all(vals[i]), (x)) - vals[i].begin() + 1)

    void Update(int i, int jj, int val)
    {
        for (; i <= m; i += i & -i) for (int j = GetId(i, jj); j <= sz(vals[i]); j += j & -j)
            bit[i][j] += val;
    }

    int Get(int i, int jj)
    {
        int res = 0;
        for (; i; i ^= i & -i) for (int j = GetId(i, jj); j; j ^= j & -j)
            res += bit[i][j];
        
        return res;
    }
};

int n, l, c;
vector<ii> adj[N];

int h[N], d[N];

int in[N], out[N];
int node[N];
int timer = 0;

int bigChild[N];
FenwickTree bit;

ll res = 0;

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    int mx = 0;

    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p) continue;

        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFSPrepare(v, u);
        if (maxi(mx, out[v] - in[v] + 1)) bigChild[u] = v;
    }

    out[u] = timer;
}

void DFS(int u, int p, bool prepare)
{
    if (bigChild[u])
    {
        DFS(bigChild[u], u, prepare);
        FOR(i, in[bigChild[u]], out[bigChild[u]])
        {
            int z = node[i];
            if (prepare) bit.FakeUpdate(h[z], d[z]);
            else bit.Update(h[z], d[z], -1);
        }
    }

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p || v == bigChild[u]) continue;

        DFS(v, u, prepare);
        FOR(i, in[v], out[v]) 
        {
            int z = node[i];

            if (prepare)
            { 
                bit.FakeUpdate(h[z], d[z]);
                bit.FakeGet(l + 2 * h[u] - h[z], c + 2 * d[u] - d[z]);
            }
            else
            {
                bit.Update(h[z], d[z], 1);
                res += bit.Get(l + 2 * h[u] - h[z], c + 2 * d[u] - d[z]);
            }
        }
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

    DFSPrepare(1, -1);

    bit = FenwickTree(n, 1e9);
    DFS(1, -1, true);

    bit.Compress();
    DFS(1, -1, false);

    cout << res;

    return 0;
}