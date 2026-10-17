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
#define name "thientai"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e5 + 5;
int const MOD = 1e9 + 22071997;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

struct DSU
{
    vector<int> par, sz;
    multiset<int, greater<int>> s;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i, sz[i] = 1;
            s.insert(1);
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

        s.erase(s.find(sz[u]));
        s.erase(s.find(sz[v]));
        s.insert(sz[u] + sz[v]);

        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};

int n, m, q;

ii e[N], qr[N];
DSU dsu;

bool del[N];
int pre[N];

int res[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    FOR(i, 1, m) cin >> e[i].F >> e[i].S;
    FOR(i, 1, q)
    {
        string type;
        cin >> type;

        if (type == "DEL") cin >> qr[i].F, qr[i].S = -1, del[qr[i].F] = true;
        else cin >> qr[i].F >> qr[i].S;
    }

    dsu = DSU(n);
    FOR(i, 1, m) if (!del[i]) dsu.Union(e[i].F, e[i].S);

    FORD(i, q, 1)
    {
        if (qr[i].S == -1) dsu.Union(e[qr[i].F].F, e[qr[i].F].S);
        else
        {
            int idx = -1;

            for (auto &x : dsu.s)
            {
                idx++;

                pre[idx] = 0;
                if (idx) pre[idx] = pre[idx - 1];
                Add(pre[idx], x);

                if (idx == qr[i].S) break;
            }

            FOR(j, qr[i].F, qr[i].S) Add(res[i], pre[min(idx, j)]);
        }
    }

    FOR(i, 1, q) if (qr[i].S != -1) cout << res[i] << '\n';

    return 0;
}