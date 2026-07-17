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
    int n, cc;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }

        cc = n;
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
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        cc--;
    }
};

struct Query
{
    int type, u, v, id;

    void Input()
    {
        cin >> type >> u >> v;
    }
};

int const N = 1e5 + 5;
int const BK = 314;
int const GR = N / BK + 5;
int const oo = 1e9;
int bkId[N], bkL[GR], bkR[GR];

int n, m, q;

Query qr[N];
DSU dsu;

int cnt[N];
bool mark[N];

int cnt0[N];
int ccId[N];

vector<int> edges;
int cc = 0;

void Init()
{
    FOR(i, 1, q)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

void Compress()
{
    vector<pair<int, int>> vals;

    FOR(i, 1, q) vals.push_back({qr[i].u, qr[i].v});
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, q) qr[i].id = lower_bound(all(vals), make_pair(qr[i].u, qr[i].v)) - vals.begin() + 1;
}

void Build(int l, int r)
{
    edges = {};
    cc = 0;

    FOR(i, l, r) cnt0[qr[i].id] += qr[i].type == 1 ? 1 : -1;
    FOR(i, l, r) if (cnt0[qr[i].id]) edges.push_back(qr[i].id);
    FOR(i, r + 1, bkR[bkId[l]]) if (mark[qr[i].id] && cnt[qr[i].id]) edges.push_back(qr[i].id);

    for (auto &e : edges)
    {
        if (!ccId[qr[e].u]) ccId[qr[e].u] = ++cc;
        if (!ccId[qr[e].v]) ccId[qr[e].v] = ++cc;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    dsu = DSU(n);

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        dsu.Union(u, v);
    }

    FOR(i, 1, q) qr[i].Input();

    Init();
    Compress();

    cout << dsu.cc << ' ';

    DSU ini = dsu;
    FOR(id, 1, bkId[q])
    {
        memset(cnt, 0, sizeof cnt);
        memset(mark, false, sizeof mark);

        FOR(i, bkL[id], bkR[id]) if (qr[i].type == 2) mark[qr[i].id] = -oo;
        dsu = ini;
        
        FOR(i, 1, bkR[id - 1]) cnt[qr[i].id] += qr[i].type == 1 ? 1 : -1;
        FOR(i, 1, bkR[id - 1]) if (!mark[qr[i].id] && cnt[qr[i].id] > 0) dsu.Union(qr[i].u, qr[i].v);
        
        int res = dsu.cc;

        FOR(i, bkL[id], bkR[id])
        {
            Build(bkL[id], i);
            DSU usd(cc);

            for (auto &e : edges) usd.Union(ccId[qr[e].u], ccId[qr[e].v]);
            for (auto &e : edges) ccId[qr[e].u] = ccId[qr[e].v] = 0;
            
            cout << res - (cc - usd.cc) << ' ';
        }
    }

    return 0;
}