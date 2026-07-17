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
    int u, v, c, x;

    void Input()
    {
        cin >> u >> v >> c >> x; 
    }
};

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n, cnt;

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
        n = cnt = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        return par[v] == v ? v : Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b];
        par[b] = a;
        cnt--;
    }
};

int const N = 1009;
int const oo = 1e9 + 2;

int n, m, q, v;

DSU dsu;
Edge edges[N];
int node[N];

bool Check()
{
    int id = dsu.Find(node[1]);
    FOR(i, 1, q) if (dsu.Find(node[i]) != id) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q >> v;
    REP(i, m) edges[i].Input();
    FOR(i, 1, q) cin >> node[i];

    int res = oo;
    int haha = 0;

    dsu = DSU(n);

    REP(mask, MK(m))
    {
        dsu.MakeSet();
        int cost = 0, val = 0;

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            dsu.Union(edges[i].u, edges[i].v);
            cost += edges[i].c;
            val += edges[i].x;
        }

        if (val < v) continue;

        if (!Check()) continue;
        if (mini(res, cost)) haha = mask;
    }

    if (res == oo) cout << -1;
    else
    {
        cout << res << '\n' << __builtin_popcount(haha) << '\n';
        for (int tmp = haha; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            cout << i + 1 << ' ';
        }
    }

    return 0;
}