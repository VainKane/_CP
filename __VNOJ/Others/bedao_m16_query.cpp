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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e5 + 5;

struct SegmentTree
{
    vector<int> t;
    vector<int> lzAnd, lzVal;
    int n;

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }

        int mid = l + r >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1 | 1, mid + 1, r, a);

        t[v] = t[v << 1] | t[v << 1 | 1];
    }

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;

        t.assign(4 * n, 0);
        lzAnd.assign(4 * n, MK(30) - 1);
        lzVal.assign(4 * n, -1);

        if (n) Build(1, 1, n, a);
    }

    void Apply(int v)
    {
        if (lzVal[v] != -1)
        {
            t[v] = lzVal[v];
            lzAnd[v] = MK(30) - 1;
        }

        if (lzAnd[v] != MK(30) - 1)
        {
            if (lzVal[v] != -1) lzVal[v] &= lzAnd[v];
            else t[v] &= lzAnd[v];
        }
    }

    void Lazy(int v)
    {
        FOR(u, v << 1, v << 1 | 1)
        {
            if (lzVal[v] != -1) lzVal[u] = lzVal[v];
            lzAnd[u] &= lzAnd[v];
            Apply(u);
        }

        lzVal[v] = -1;
        lzAnd[v] = MK(30) - 1;
    }

    void AndUpdate(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            lzAnd[v] &= val;
            Apply(v);
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        AndUpdate(v << 1, l, mid, left, right, val);
        AndUpdate(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = t[v << 1] | t[v << 1 | 1];
    }

    void ValUpdate(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            lzVal[v] = val;
            Apply(v);
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        ValUpdate(v << 1, l, mid, left, right, val);
        ValUpdate(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = t[v << 1] | t[v << 1 | 1];
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        int val1 = Get(v << 1, l, mid, left, right);
        int val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return val1 | val2;
    }

    void AndUpdate(int l, int r, int val)
    {
        if (l > r) return;
        AndUpdate(1, 1, n, l, r, val);
    }

    void ValUpdate(int l, int r, int val)
    {
        if (l > r) return;
        ValUpdate(1, 1, n, l, r, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

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
        int type, l, r, x;
        cin >> type >> l >> r;

        if (type == 1)
        {
            cin >> x;
            it.AndUpdate(l, r, x);
        }
        else if (type == 2)
        {
            cin >> x;
            it.ValUpdate(l, r, x);
        }
        else cout << it.Get(l, r) << '\n';
    }

    return 0;
}