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

int const N = 5e5 + 5;
int const BK = 707;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

struct SQRTDS
{
    vector<int> cnt;
    vector<bool> mark;
    int n;

    SQRTDS(int _n = 5e5)
    {
        n = _n;
        cnt.assign(n + 5, 0);
        mark.assign(n + 5, 0);
    }

    void Update(int idx, int delta)
    {
        mark[idx] = !mark[idx];
        cnt[bkId[idx]] += delta;
    }

    int Get()
    {
        FOR(id, 1, bkId[n]) if (cnt[id]) FOR(i, bkL[id], bkR[id]) if (mark[i]) return i;
        return 0;
    }
};

struct Query
{
    int l, r, id;

    void Input(int _id)
    {
        id = _id;
        cin >> l >> r;
    }

    bool operator < (Query const other) const
    {
        if (bkId[l] != bkId[other.l]) return l < other.l;
        if (bkId[l] & 1) return r < other.r;
        return r > other.r;
    }
};

int n, q;
int a[N];

Query qr[N];
int res[N];

SQRTDS s;
int cnt[N];

void Init()
{
    FOR(i, 1, 5e5)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    sort(qr + 1, qr + q + 1);
}

void Update(int val, int delta)
{
    if (cnt[val] == 1) s.Update(val, -1);
    cnt[val] += delta;
    if (cnt[val] == 1) s.Update(val, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> q;
    FOR(i, 1, q) qr[i].Input(i);

    Init();

    int l = 1, r = 0;
    FOR(i, 1, q)
    {
        while (r < qr[i].r) Update(a[++r], 1);
        while (r > qr[i].r) Update(a[r--], -1);

        while (l > qr[i].l) Update(a[--l], 1);
        while (l < qr[i].l) Update(a[l++], -1);

        res[qr[i].id] = s.Get();
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}