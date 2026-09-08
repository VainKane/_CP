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
#define name "dayso"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5e4 + 5;
int const BK = 400;
int bkId[N];

struct Query
{
    int l, r, delta, id;

    bool operator < (Query const other) const
    {
        if (bkId[l] != bkId[other.l]) return l < other.l;
        if (bkId[l] & 1) return r < other.r;
        return r > other.r;
    }
};

int n, q;

int a[N];

vector<Query> queries;
int cnt[2][N];

long long res[N];
long long cur = 0;

void Init()
{
    FOR(i, 1, n) bkId[i] = i / BK;
    sort(all(queries));
}

void Update(int &val, int delta, int id)
{
    cnt[id][val] += delta;
    cur += delta * cnt[id ^ 1][val];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q)
    {
        int l, r, u, v;
        cin >> l >> r >> u >> v;

        queries.push_back({r, v, 1, i});
        queries.push_back({v, l - 1, -1, i});
        queries.push_back({r, u - 1, -1, i});
        queries.push_back({l - 1, u - 1, 1, i});
    }

    Init();
    int l = 0, r = l - 1;

    for (auto &qr : queries)
    {
        while (r < qr.r) Update(a[++r], 1, 0);
        while (r > qr.r) Update(a[r--], -1, 0);

        while (l < qr.l) Update(a[++l], 1, 1);
        while (l > qr.l) Update(a[l--], -1, 1);

        res[qr.id] += cur * qr.delta;
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}