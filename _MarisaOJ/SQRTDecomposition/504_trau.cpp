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
int const BK = 314;
int bkId[N];

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
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
FenwickTree bit1, bit2;

pair<int, int> res[N];
int cnt[N];

void Init()
{
    FOR(i, 1, n) bkId[i] = i / BK;
    sort(qr + 1, qr + q + 1);
    bit1 = bit2 = FenwickTree(N);
}

void Update(int &val, int delta)
{
    if (val)
    {
        if (cnt[val] == 0 && delta == 1) bit2.Update(val, delta);
        if (cnt[val] == 1 && delta == -1) bit2.Update(val, delta);
        bit1.Update(val, delta);
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

        res[qr[i].id] = {bit1.Get(qr[i].a, qr[i].b), bit2.Get(qr[i].a, qr[i].b)};
    }

    FOR(i, 1, q) cout << res[i].F << ' ' << res[i].S << '\n'; 

    return 0;
}