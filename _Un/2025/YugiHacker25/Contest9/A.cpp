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
    vector<int> t;
    vector<int> lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                t[u] |= lz[v];
                lz[u] |= lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] |= val;
            lz[v] |= val;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = t[2 * v] & t[2 * v + 1];
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return MK(31) - 1;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = (l + r) >> 1;

        int val1 = Get(2 * v, l, mid, left, right);
        int val2 = Get(2 * v + 1, mid + 1, r, left, right);
 
        return val1 & val2;
   }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

int const N = 2e5 + 5;

int n, q;
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    it = SegmentTree(n);
   
    while (q--)
    {
        int type, l, r, v;
        cin >> type >> l >> r;

        if (type == 1)
        {
            cin >> v;
            it.Update(l, r, v);
        }
        else cout << it.Get(l, r) << '\n';
    }

    return 0;
}