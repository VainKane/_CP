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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const M = 3e4 + 5;
int const LOG = 20;

int n;

int a[N];
vector<int> adj[N];

namespace Sub1
{
    bool CheckSub()
    {
        return true;
    }

    long long d[N];
    int up[2 * N][LOG];
    int pos[N];
    int timer = 0;

    int GCD(int a, int b)
    {
        while (true)
        {
            if (a == 0 || b == 0 || a == b) return a | b;
            if (a > b) a %= b; else b %= a;
        }
    }

    bool cmp(int u, int v)
    {
        return pos[u] < pos[v];
    }

    void DFS(int u, int p)
    {
        up[++timer][0] = u;
        pos[u] = timer;

        for (auto &v : adj[u]) if (v != p)
        {
            d[v] = d[u] + a[v];
            DFS(v, u);
            up[++timer][0] = u;
        }
    }

    void Build()
    {
        FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
            up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
    }

    int LCA(int u, int v)
    {
        u = pos[u], v = pos[v];
        if (u > v) swap(u, v);

        int k = 31 - __builtin_clz(v - u + 1);
        return min(up[u][k], up[v - MK(k) + 1][k], cmp);
    }

    long long Dist(int u, int v)
    {
        int p = LCA(u, v);
        return d[u] + d[v] - 2 * d[p] + a[p];
    }

    void Process()
    {
        d[1] = a[1];
        DFS(1, -1);
        Build();

        long long res = 0;
        FOR(u, 1, n) FOR(v, u + 1, n) if (GCD(a[u], a[v]) > 1) res += Dist(u, v);
        cout << res;
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        FOR(u, 1, n) if (a[u] != a[1]) return false;
        return true;
    }

    int sz[N];
    long long f[N], fPar[N];
    long long s = 0;

    void DFSPrepare(int u, int p)
    {
        sz[u] = 1;

        for (auto &v : adj[u]) if (v != p)
        {
            DFSPrepare(v, u);
            f[u] += f[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    void DFS(int u, int p)
    {
        for (auto &v : adj[u]) if (v != p)
        {
            fPar[v] = f[u] + fPar[u] - f[v] - sz[v] + n - sz[v];
            DFS(v, u);
        }
    }

    void Process()
    {
        DFSPrepare(1, -1);
        DFS(1, -1);

        long long res = 0;
        FOR(u, 1, n) res += f[u] + fPar[u] + n - 1;
        cout << res / 2 * (a[1] > 1 ? a[1] : 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub1::CheckSub()) return Sub1::Process(), 0;

    return 0;
}