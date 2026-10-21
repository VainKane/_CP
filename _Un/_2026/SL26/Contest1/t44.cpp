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

int const N = MK(18) + 5;

ii Merge(ii a, ii b) { return {min(a.F, b.F), max(a.S, b.S)}; }

struct SegmentTree
{
    vector<ii> t;
    int n;

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v] = {a[l], a[l]};
            return;
        }

        int mid = l + r >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1 | 1, mid + 1, r, a);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;
        t.assign(2 * n, {n - 1, 0});
        if (n) Build(1, 0, n - 1, a);
    }

    ii Get(int v, int l, int r, int left, int right, int h, int k)
    {
        if (l > right || r < left) return {n - 1, 0};
        if (left <= l && right >= r) return t[v];

        int mid = l + r >> 1;
        ii val1 = Get((v << 1) ^ BIT(h, k), l, mid, left, right, h - 1, k);
        ii val2 = Get((v << 1 | 1) ^ BIT(h, k), mid + 1, r, left, right, h - 1, k);

        return Merge(val1, val2);
    }

    ii Get(int l, int r, int k)
    {
        if (l > r) return {n - 1, 0};
        return Get(1, 0, n - 1, l, r, __builtin_ctz(n) - 1, k);
    }
};

int n, q;

int id[N];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    REP(i, n)
    {
        int x; cin >> x;
        id[x] = i;
    }

    string type;
    int l, r, x;

    it = SegmentTree(n, id);
    int sum = 0;

    while (q--)
    {
        cin >> type;

        if (type == "Update")
        {
            cin >> x;
            sum ^= x;
        }
        else
        {
            cin >> l >> r;
            auto seg = it.Get(l, r, sum);
            cout << seg.S - seg.F + 1 << '\n';
        }
    }

    return 0;
}