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

int const N = 1e7 + 5;
int MOD;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

struct SegmentTree
{
    vector<int> t;
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

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;
        t.assign(4 * n, 0);
        if (n) Build(1, 1, n, a);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return -1;
        if (left <= l && right >= r) return t[v];

        int mid = l + r >> 1;
        int val1 = Get(v << 1, l, mid, left, right);
        int val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return max(val1, val2);
    }

    int Get(int l, int r) { return Get(1, 1, n, l, r); }
};

int n, q, x, y, z;

int a[N];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q >> x >> y >> z >> MOD;

    a[1] = x;
    FOR(i, 2, n) a[i] = (1LL * a[i - 1] * y + z) % MOD;

    it = SegmentTree(n, a);
    int res = 0;

    FOR(i, 1, q)
    {
        int l = i % n + 1;
        int r = 1LL * i * i % n + 1;

        if (l > r) swap(l, r);
        Add(res, it.Get(l, r));
    }

    cout << res;

    return 0;
}