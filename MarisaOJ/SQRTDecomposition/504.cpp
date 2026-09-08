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

int const N = 1e5 + 5;
int const BK = 447;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

struct SQRTDS
{
    vector<int> cnt;
    vector<int> sum;
    int n;

    SQRTDS(int _n = 0)
    {
        n = _n;
        cnt.assign(n + 5, 0);
        sum.assign(GR, 0);
    }

    void Update(int &idx, int &val)
    {
        cnt[idx] += val;
        sum[bkId[idx]] += val;
    }

    int Get(int &l, int &r)
    {
        int res = 0;

        if (bkId[l] == bkId[r])
        {
            FOR(i, l, r) res += cnt[i];
            return res;
        }

        FOR(i, bkId[l] + 1, bkId[r] - 1) res += sum[i];
        return res + Get(l, bkR[bkId[l]]) + Get(bkL[bkId[r]], r);
    }
};

struct Query
{
    int l, r, a, b, id;

    Query()
    {
        l = r = a = b = id = 0;
    }

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> r >> a >> b;
    }

    bool operator < (Query const other) const
    {
        if (bkId[l] != bkId[other.l]) return l < other.l;
        if (bkId[l] & 1) return r > other.r;
        return r < other.r;
    } 
};

int n, q;
int a[N];

Query qr[N];
SQRTDS cnt1, cnt2;
int cnt[N];

pair<int, int> res[N];

void Init()
{
    FOR(i, 1, 1e5) 
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    sort(qr + 1, qr + q + 1);
    cnt1 = cnt2 = SQRTDS(N);
}

void Update(int &val, int delta)
{
    if (val)
    {
        if (cnt[val] == 0 && delta == 1) cnt2.Update(val, delta);
        if (cnt[val] == 1 && delta == -1) cnt2.Update(val, delta);
        cnt1.Update(val, delta);
    }

    cnt[val] += delta;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) qr[i].Input(i);

    Init();

    int l = 1, r = 0;
    FOR(i, 1, q)
    {
        while (r < qr[i].r) Update(a[++r], 1);
        while (r > qr[i].r) Update(a[r--], -1);

        while (l > qr[i].l) Update(a[--l], 1);
        while (l < qr[i].l) Update(a[l++], -1);

        res[qr[i].id] = {cnt1.Get(qr[i].a, qr[i].b), cnt2.Get(qr[i].a, qr[i].b)};
    }

    FOR(i, 1, q) cout << res[i].F << ' ' << res[i].S << '\n'; 

    return 0;
}