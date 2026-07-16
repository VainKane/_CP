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
int const BK = sqrt(N);

struct Query
{
    int l, r, x, id;

    Query()
    {
        l = r = x = id = 0;
    }

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> r >> x;
    }

    bool operator < (Query const other) const
    {
        if (l / BK != other.l / BK) return l < other.l;
        if ((l / BK) & 1) return r < other.r;
        return r > other.r;
    }
};

int n, q;

int a[N];
Query qr[N];

int cnt[N];
int f[N];

int res[N];

void Update(int val, int delta)
{
    f[cnt[val]]--;
    cnt[val] += delta;
    f[cnt[val]]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, q) qr[i].Input(i);
    sort(qr + 1, qr + q + 1);

    int l = 1, r = 0;

    FOR(i, 1, q)
    {
        while (r < qr[i].r) Update(a[++r], 1);
        while (r > qr[i].r) Update(a[r--], -1);

        while (l > qr[i].l) Update(a[--l], 1);
        while (l < qr[i].l) Update(a[l++], -1);

        assert(qr[i].x);
        res[qr[i].id] = f[qr[i].x];
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}