#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "CAU5"

struct DSU
{
    vector<int> par;
    vector<int> sz;
    long long res = 0;
    int n;

    void Init()
    {
        FOR(i, 1, n) 
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.resize(n + 5);
        sz.resize(n + 5);

        if (n) Init();
    }

    long long Cal(int x)
    {
        return 1ll * x * (x - 1) / 2;
    }

    int Find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        
        res -= Cal(sz[a]);
        res -= Cal(sz[b]);
        
        sz[a] += sz[b];
        par[b] = a;

        res += Cal(sz[a]);
    }
};

int const N = 2e5 + 5;

int n, m;
vector<pair<int, int>> edges[N];

long long res[N];
DSU dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].push_back({u, v});
    }

    dsu = DSU(n);

    FOR(i, 1, 2e5) 
    {
        for (auto &e : edges[i]) dsu.Union(e.F, e.S);
        res[i] = dsu.res;
    }

    while (m--) 
    {
        int q; cin >> q;
        cout << res[q] << '\n';
    }

    return 0;
}