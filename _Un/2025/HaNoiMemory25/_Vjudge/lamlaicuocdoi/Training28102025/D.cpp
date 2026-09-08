#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define name "milkvisits"

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
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        Update(l, val);
        Update(r + 1, -val);
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

struct Query
{
    int u, v, i;
};

int const N = 1e5 + 5;
int const LOG = 17;

int n, m;
vector<int> adj[N];

FenwickTree bit;

int up[N][20];
int h[N];

int in[N], out[N];
int cnt = 0;

vector<int> c[N];
vector<Query> qr[N];

bool res[N];

void DFS(int u, int p)
{
    in[u] = ++cnt;
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
    out[u] = cnt;
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        u = up[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i]) 
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".in", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        c[x].push_back(i);
    }

    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, m)
    {
        int u, v, k;
        cin >> u >> v >> k;
        qr[k].push_back({u, v, i});
    }

    bit = FenwickTree(n);
    DFS(1, -1);

    FOR(i, 1, n)
    {
        for (auto &u : c[i - 1]) bit.Update(in[u], out[u], -1);
        for (auto &u : c[i]) bit.Update(in[u], out[u], 1);

        for (auto &q : qr[i])
        {
            int u = in[q.u];
            int v = in[q.v];
            int p = LCA(q.u, q.v);

            res[q.i] = bit.Get(u) + bit.Get(v) - bit.Get(in[p]) - bit.Get(in[up[p][0]]);
        }
    }

    FOR(i, 1, m) cout << res[i];

    return 0;
}