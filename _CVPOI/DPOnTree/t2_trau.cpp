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

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

int const N = 36;

int n;
vector<int> adj[N];

bool mark[N];
DSU dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dsu = DSU(n);
    int res = 0, cnt = 1;

    REP(mask, MK(n))
    {
        REP(i, n) mark[i + 1] = BIT(i, mask);
        dsu.MakeSet();
        
        FOR(u, 1, n) for (auto &v : adj[u]) if (!mark[u] && !mark[v]) dsu.Union(u, v);
        
        int tmp = 0;
        FOR(u, 1, n) tmp += !mark[u] && dsu.Find(u) == u;

        if (maxi(res, tmp)) cnt = 1;
        else if (res == tmp) cnt++;
    }

    cout << res << ' ' << cnt;

    return 0;
}