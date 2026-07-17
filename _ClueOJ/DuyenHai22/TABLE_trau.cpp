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
    vector<long long> lz;
    vector<int> sz;
    int n;

    void Build(int v, int l, int r, int a[])
    {
        sz[v] = r - l + 1;

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

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        sz.assign(4 * n, 0);

        if (n) Build(1, 1, n, a);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += lz[v] * sz[u];
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += 1LL * val * sz[v];
            lz[v] += val;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

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

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

int const N = 509;

int m, n, q;
int a[N];
SegmentTree it[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> q;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) cin >> a[j];
        it[i] = SegmentTree(n, a);
    }

    while (q--)
    {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;

        if (type == 1)
        {
            int val; cin >> val;
            FOR(i, x1, x2) it[i].Update(y1, y2, val);
        }
        else
        {
            long long res = 0;
            FOR(i, x1, x2) res += it[i].Get(y1, y2);
            cout << res << '\n';
        }
    }

    return 0;
}