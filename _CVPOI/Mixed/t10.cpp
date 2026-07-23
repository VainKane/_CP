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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 3e5 + 5;

ll C2(int x) { return x * (x - 1LL) / 2; }

queue<pair<int, int>> q;
map<int, int> mp[N];

struct DSU
{
    vector<int> par, sz;
    int n;

    void MakeSet() { FOR(i, 1, n) par[i] = i, sz[i] = 1; }
    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        MakeSet();
    }

    int Find(int v) { return par[v] == v ? v : par[v] = Find(par[v]); }

    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v) return;

        if (sz(mp[u]) < sz(mp[v])) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;

        for (auto &p : mp[v])
        {
            int &node = mp[u][p.F];

            if (node) q.push({node, p.S});
            node = sz(mp[node]) > sz(mp[p.S]) ? node : p.S;
        }
    }
};

int n, m, k;
DSU dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;

        int node = mp[v][w];
        if (node) q.push({node, u});
        mp[v][w] = u;
    }

    dsu = DSU(n);
    while (!q.empty())
    {
        auto p = q.front(); q.pop();
        dsu.Union(p.F, p.S);
    }

    ll res = 0;
    FOR(u, 1, n) if (dsu.Find(u) == u) res += C2(dsu.sz[u]);
    cout << res;

    return 0;
}