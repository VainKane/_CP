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

int const N = 309;

struct DSU
{
    vector<int> par, sz;
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
        par = sz = vector<int>(n + 5, 0);
        MakeSet();
    }

    int Find(int v) { return par[v] == v ? v : par[v] = Find(par[v]); }

    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};

int n, m;
DSU dsu;

int k[N];
vector<int> nodes[N];

void Print(vector<int> &v)
{
    int sum = 0;
    for (auto &x : v) sum += x;
    if (sum != n - 1) v.push_back(n - sum);

    sort(all(v), greater<int>());
    if (sum == n - 1) v.back()++;

    sort(all(v), greater<int>());

    cout << sz(v) << '\n';
    for (auto &x : v) cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    dsu = DSU(n);
    int s = 0;

    int mn = n;
    FOR(i, 1, n)
    {
        dsu.MakeSet();

        cin >> k[i];
        REP(haha, k[i])
        {
            int u, v;
            cin >> u >> v;
            dsu.Union(u, v);
        }

        FOR(u, 1, n - 1) if (dsu.Find(u) == u && dsu.sz[u] != 1) nodes[i].push_back(dsu.sz[u]);
        sort(all(nodes[i]), greater<int>());

        mini(mn, sz(nodes[i]));
        s += k[i];
    }

    int m = s / (n - 2);
    vector<vector<int>> v;

    FOR(i, 1, n)
    {
        if (sz(nodes[i]) == mn) v.push_back(nodes[i]);
        if (k[i] == m)
        {
            int sum = 0;
            for (auto &x : nodes[i]) sum += x;
            REP(haha, n - sum) nodes[i].push_back(1);

            sort(all(nodes[i]), greater<int>());
            cout << sz(nodes[i]) << '\n';
            for (auto &x : nodes[i]) cout << x << ' ';
            return 0;
        }
    }

    sort(all(v), greater<vector<int>>());
    Print(v[0]);

    return 0;
}