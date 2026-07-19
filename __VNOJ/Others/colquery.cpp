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
    vector<int> par, sz;
    vector<map<int, int>> mp;
    int n;

    void MakeSet(vector<int> &a)
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = mp[i][a[i]] = 1;
        }
    }

    DSU(vector<int> a)
    {
        n = sz(a) - 1;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        mp.assign(n + 5, map<int, int>());

        MakeSet(a);
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;
        
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        
        for (auto &p : mp[b]) mp[a][p.F] += p.S;
        mp[b].clear();
    }

    int Query(int u, int c)
    {
        u = Find(u);
        return mp[u].find(c) != mp[u].end() ? mp[u][c] : 0;
    }
};

int n, q;
vector<int> a = {0};

DSU dsu({0});

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        a.push_back(x);
    }

    dsu = DSU(a);

    while (q--)
    {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) dsu.Union(u, v);
        else cout << dsu.Query(u, v) << '\n';
    }

    return 0;
}