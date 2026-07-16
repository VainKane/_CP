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
    vector<int> sum;
    vector<int> a;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
            sum[i] = a[i];
        }
    }

    DSU(int _n = 0, int _a[] = {})
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        sum.assign(n + 5, 0);
        a.assign(n + 5, 0);
        
        if (n) FOR(i, 1, n) a[i] = _a[i];
        MakeSet();
    }

    int Find(int v)
    {
        return par[v] == v ? v : par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        sum[a] += sum[b];
        sz[a] += sz[b];
        par[b] = a;
    }
};

int const N = 36;

int n, x;

int a[N];
pair<int, int> edges[N];
DSU dsu;

bool Valid(int mask)
{
    dsu.MakeSet();
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        dsu.Union(edges[i].F, edges[i].S);
    }

    FOR(u, 1, n) if (dsu.Find(u) == u && dsu.sum[u] < 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;

    FOR(i, 1, n)
    {
        int val; cin >> val;
        a[i] = x - val;
    }

    REP(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    dsu = DSU(n, a);

    int res = n - 1;
    REP(mask, MK(n - 1)) if (Valid(mask)) mini(res, __builtin_popcount(mask));
    cout << res;

    return 0;
}