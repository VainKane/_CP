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
int const oo = 5e5;

struct SegmentTree
{
    vector<pair<int, int>> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, {oo, 0});
    }

    void Update(int v, int l, int r, int pos, pair<int, int> val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    pair<int, int> Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return {oo, 0};
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        auto p1 = Get(2 * v, l, mid, left, right);
        auto p2 = Get(2 * v + 1, mid + 1, r, left, right);

        return min(p1, p2);
    }

    void Update(int pos, pair<int, int> val)
    {
        if (pos < 1 || pos > n) return;
        Update(1, 1, n, pos, val);
    }

    pair<int, int> Get(int l, int r)
    {
        if (l > r) return {oo, 0};
        return Get(1, 1, n, l, r);
    }
};

int n, q;

vector<pair<int, int>> qr[N];
SegmentTree it;

int a[N];
int pre[N], last[N];
int res[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }

    cin >> q;
    FOR(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        qr[r].push_back({l, i});
    }

    it = SegmentTree(n);

    FOR(r, 1, n)
    {
        it.Update(pre[r], {oo, 0});
        it.Update(r, {pre[r], r});

        for (auto &query : qr[r])
        {
            int l = query.F;
            int id = query.S;

            auto p = it.Get(l, r);
            if (p.F < l) res[id] = a[p.S];
        }
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}