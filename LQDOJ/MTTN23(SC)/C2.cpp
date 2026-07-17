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
#define name "02"

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int u, v, c, x, id;

    void Input(int _id)
    {
        id = _id;
        cin >> u >> v >> c >> x; 
    }

    bool operator < (Edge const other) const
    {
        return c < other.c;
    }
};

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n;

    void MakeSet()
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
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        return par[v] == v ? v : Find(par[v]);
    }

    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b];
        par[b] = a;
        return true;
    }
};

int const N = 1009;
int const oo = 1e9 + 2;

int n, m, q, v;

DSU dsu;
Edge edges[N];

void Kruskal()
{
    sort(edges + 1, edges + m + 1);
    dsu = DSU(n);

    vector<int> haha;
    int res = 0;

    FOR(i, 1, m) if (dsu.Union(edges[i].u, edges[i].v))
    {
        res += edges[i].c;
        haha.push_back(edges[i].id);
    }

    cout << res << '\n' << sz(haha) << '\n';
    for (auto &id : haha) cout << id << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q >> v;
    FOR(i, 1, m) edges[i].Input(i);
    FOR(i, 1, q) cin >> q;

    Kruskal();

    return 0;
}