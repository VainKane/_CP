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

struct SegmentTree
{
    vector<pair<int, int>> t;
    int n;

    pair<int, int> Merge(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.F > b.F) return {a.F, max(a.S, b.F)};
        return {b.F, max(b.S, a.F)};
    }

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v] = {a[l], 0};
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid, a);
        Build(2 * v + 1, mid + 1, r, a);
        t[v] = Merge(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;
        t.assign(4 * n, {0, 0});
        if (n) Build(1, 1, n, a);
    }

    pair<int, int> Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return {0, 0};
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        auto p1 = Get(2 * v, l, mid, left, right);
        auto p2 = Get(2 * v + 1, mid + 1, r, left, right);

        return Merge(p1, p2);
    }

    pair<int, int> Get(int l, int r)
    {
        if (l >= r) return {0, 0};
        return Get(1, 1, n, l, r);
    }
};

int const N = 1e5 + 5;

int n, q;
int a[N];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(n, a);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        auto p = it.Get(l, r);
        cout << p.F + p.S << '\n';
    }

    return 0;
}
