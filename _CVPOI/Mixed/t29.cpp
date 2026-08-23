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

int const N = 2e5 + 5;

struct DSU
{
    vector<int> par, sz;
    int n, cnt;

    void MakeSet()
    {
        cnt = n;
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

    int Find(int v) { return par[v] == v ? v : par[v] = Find(par[v]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        
        sz[u] += sz[v];
        par[v] = u;
        cnt--;
    }
};

int n, m;
vector<int> adj[N];

bool res[N];
DSU dsu;

int qr[N];
bool mark[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) cin >> qr[i];

    dsu = DSU(n);
    FORD(i, n, 1)q
    {
        mark[qr[i]] = true;

        for (auto &v : adj[qr[i]]) if (mark[v]) dsu.Union(qr[i], v);
        res[i] = dsu.cnt == i;
    }

    FOR(i, 1, n) cout << (res[i] ? "YES\n" : "NO\n");

    return 0;
}