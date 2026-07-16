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
        return par[v] == v ? v : par[v] = Find(par[v]);
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

struct Edge
{
    int u, v, w;

    bool operator < (Edge const other) const
    {
        return w < other.w;
    }
};

int const N = 1009;

int n;
vector<Edge> edges;
DSU dsu;

int Kruskal()
{
    sort(all(edges));
    dsu = DSU(2 * n);

    int res = 0;
    for (auto &e : edges) if (dsu.Union(e.u, e.v)) res += e.w;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        edges.clear();

        FOR(i, 1, n - 1)
        {
            int w; cin >> w;
            edges.push_back({i, i + 1, w});
        }

        FOR(i, 1, n - 1)
        {
            int w; cin >> w;
            edges.push_back({n + i, n + i + 1, w});
        }

        FOR(i, 1, n)
        {
            int w; cin >> w;
            edges.push_back({i, n + i, w});
        }

        cout << Kruskal() << '\n';
    }

    return 0;
}