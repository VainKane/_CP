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
int const M = MK(20) + 5;
int const BK = sqrt(N);

struct Query
{
    int l, r, id;

    Query()
    {
        l = r = id = 0;
    }

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> r;
        l--;
    }

    bool operator < (Query const other) const
    {
        if (l / BK != other.l / BK) return l < other.l;
        if ((l / BK) & 1) return r > other.r;
        return r < other.r;
    }
};

int n, m, k;

int pre[N];
Query qr[N];

int cnt[M];

long long res[N];
long long cur = 0;

void UpdateSub(int val)
{
    cnt[val]--;
    cur -= cnt[val ^ k];
}

void UpdateAdd(int val)
{
    cur += cnt[val ^ k];
    cnt[val]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        pre[i] = pre[i - 1] ^ x;
    }

    FOR(i, 1, m) qr[i].Input(i);
    sort(qr + 1, qr + m + 1);

    int l = 1, r = 0;
    FOR(i, 1, m)
    {
        while (r < qr[i].r) UpdateAdd(pre[++r]);
        while (r > qr[i].r) UpdateSub(pre[r--]);

        while (l > qr[i].l) UpdateAdd(pre[--l]);
        while (l < qr[i].l) UpdateSub(pre[l++]);

        res[qr[i].id] = cur;
    }

    FOR(i, 1, m) cout << res[i] << '\n';

    return 0;
}