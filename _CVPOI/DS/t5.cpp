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
    vector<long long> t;
    vector<int> len, lz;
    int n, k;

    void Build(int v, int l, int r, int a[])
    {
        len[v] = r - l + 1;

        if (l == r)
        {
            t[v] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1 | 1, mid + 1, r, a);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    SegmentTree(int _n = 0, int _k = 0, int a[] = {})
    {
        n = _n, k = _k;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        len.assign(4 * n, 0);

        if (n) Build(1, 1, n, a);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] = 1LL * len[u] * (MK(k) - 1) - t[u];
                lz[u] ^= 1;
            }

            lz[v] = 0;
        }
    }

    void RangeUpdate(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = 1LL * len[v] * (MK(k) - 1) - t[v];
            lz[v] ^= 1;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        RangeUpdate(v << 1, l, mid, left, right);
        RangeUpdate(v << 1 | 1, mid + 1, r, left, right);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    void PointUpdate(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        if (pos <= mid) PointUpdate(v << 1, l, mid, pos, val);
        else PointUpdate(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    long long Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = (l + r) >> 1;

        long long val1 = Get(v << 1, l, mid, left, right);
        long long val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return val1 + val2;
    }

    void RangeUpdate(int l, int r)
    {
        if (l > r) return;
        RangeUpdate(1, 1, n, l, r);
    }

    void PointUpdate(int pos, int val)
    {
        if (pos < 1 || pos > n) return;
        PointUpdate(1, 1, n, pos, val);
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

int const N = 2e5 + 5;

int n, k;
int a[N];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(n, k, a);

    int q; cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) it.PointUpdate(x, y);
        else if (type == 2) it.RangeUpdate(x, y);
        else cout << it.Get(x, y) << '\n';
    }

    return 0;
}