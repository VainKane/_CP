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

int const N = 2e5 + 5;

int n, d;
vector<int> adj[N];

int h[N];

struct cmp
{
    bool operator () (int u, int v) const
    {
        return h[u] < h[v];
    }
};

struct DSU
{
    vector<int> par, sz;
    vector<multiset<int, cmp>> mp;

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
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        mp.assign(n + 5, multiset<int, cmp> ());

        MakeSet();
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        int u = a;
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    
        mp[a].insert(all(mp[b]));
        mp[b].clear();

        while (true)
        {
            if (sz(mp[a]) < 2) break;

            auto it = mp[a].begin();
            it++;

            if (h[*it] + h[*mp[a].begin()] - 2 * h[u] >= d) break;
            mp[a].erase(mp[a].begin());
        }
    }
};

DSU dsu;

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        dsu.Union(u, v);
    }

    auto &mp = dsu.mp[dsu.Find(u)];
    if (mp.empty() || h[*mp.begin()] - h[u] >= d) mp.insert(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dsu = DSU(n);

    DFSPrepare(1, -1);
    DFS(1, -1);

    auto &mp = dsu.mp[dsu.Find(1)];

    cout << sz(mp) << '\n';
    for (auto &x : mp) cout << x << ' ';

    return 0;
}