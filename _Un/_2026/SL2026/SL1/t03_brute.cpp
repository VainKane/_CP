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

int const N = 3e6 + 5;
int const oo = 1e9 + 9;

struct SegmentTree
{
    vector<int> t, lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, oo);
        lz.assign(4 * n, oo);
    }

    void Lazy(int v)
    {
        if (lz[v] == oo) return;
        FOR(u, v << 1, v << 1 | 1)
        {
            mini(t[u], lz[v]);
            mini(lz[u], lz[v]);
        }

        lz[v] = oo;
    }

    void Update(int v, int l, int r, int &left, int &right, int &val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            mini(t[v], val);
            mini(lz[v], val);
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    int Get(int v, int l, int r, int &pos)
    {
        if (l == r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        return pos <= mid ? Get(v << 1, l, mid, pos) : Get(v << 1 | 1, mid + 1, r, pos);
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Get(int pos) { return Get(1, 1, n, pos); }
};

int n;

int a[N];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(n);

    it.Update(1, 1, 0);
    FOR(i, 1, n - 1) it.Update(i + 1, min(i + a[i], n), it.Get(i) + 1);
    
    int res = it.Get(n);
    cout << (res < oo ? res : -1);

    return 0;
}