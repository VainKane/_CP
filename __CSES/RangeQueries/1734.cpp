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

int const N = 2e5 + 5;
int const BK = 314;
int bkId[N];

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

int cnt[N];
int cur = 0;

int res[N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
}

void Init()
{
    FOR(i, 1, n) bkId[i] = (i - 1) / BK + 1;
    sort(qr + 1, qr + q + 1);
}

void Update(int val, int delta)
{
    if (cnt[val] == 0 && delta == 1) cur++;
    if (cnt[val] == 1 && delta == -1) cur--;
    cnt[val] += delta;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) qr[i].Input(i);

    Compress();
    Init();

    int l = 1, r = 0;
    FOR(i, 1, q)
    {
        while (r < qr[i].r) Update(a[++r], 1);
        while (r > qr[i].r) Update(a[r--], -1);

        while (l > qr[i].l) Update(a[--l], 1);
        while (l < qr[i].l) Update(a[l++], -1);

        res[qr[i].id] = cur;
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}