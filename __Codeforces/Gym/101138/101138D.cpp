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

int const N = 5e4 + 5;
int const BK = 224;
int bkId[N];

struct Query
{
    int l, r, d, id;

    bool operator < (Query const other) const
    {
        if (bkId[l] != bkId[other.l]) return l < other.l;
        if (bkId[l] & 1) return r < other.r;
        return r > other.r;
    }
};

int n, q;

int a[N];
vector<Query> qrs;
long long res[4 * N];

int cnt[2][N];
long long cur = 0;

void Init()
{
    FOR(i, 1, n) bkId[i] = (i - 1) / BK + 1;
    sort(all(qrs));
}

void Update(int val, int delta, bool id)
{
    cnt[id][val] += delta;
    cur += cnt[id ^ 1][val] * delta;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> q;
    FOR(i, 1, q)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        qrs.push_back({r1, r2, 1, i});
        qrs.push_back({r1, l2 - 1, -1, i});
        qrs.push_back({r2, l1 - 1, -1, i});
        qrs.push_back({l1 - 1, l2 - 1, 1, i});
    }

    Init();

    int l = 0, r = l - 1;
    for (auto &qr : qrs)
    {
        while (r < qr.r) Update(a[++r], 1, 0);
        while (r > qr.r) Update(a[r--], -1, 0);

        while (l < qr.l) Update(a[++l], 1, 1);
        while (l > qr.l) Update(a[l--], -1, 1);

        res[qr.id] += qr.d * cur;
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}