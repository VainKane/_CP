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

int S;

struct Query
{
    int l, r, id;

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> r;
    }

    bool operator < (Query const other) const
    {
        if (l / S != other.l / S) return l < other.l;
        if ((l / S) & 1) return r < other.r;
        return r > other.r;
    }
};

int const N = 2e5 + 5;

int n, t;

int a[N];
Query qr[N];

int cnt[5 * N];
long long res[N];

long long cur = 0;

void Update(int &val, int d)
{
    cur -= 1LL * cnt[val] * cnt[val] * val;
    cnt[val] += d;
    cur += 1LL * cnt[val] * cnt[val] * val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, t) qr[i].Input(i);

    S = n / sqrt(t);

    if (S) sort(qr + 1, qr + t + 1);
    int l = 1, r = 0;

    FOR(i, 1, t)
    {
        while (r < qr[i].r) Update(a[++r], 1);
        while (r > qr[i].r) Update(a[r--], -1);
        while (l < qr[i].l) Update(a[l++], -1);
        while (l > qr[i].l) Update(a[--l], 1);

        res[qr[i].id] = cur;
    }

    FOR(i, 1, t) cout << res[i] << '\n';

    return 0;
}