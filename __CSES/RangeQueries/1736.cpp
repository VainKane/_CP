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

int const N = 2e5 + 5;

struct SegmentTree
{
    vector<ll> t, lz, sum;
    vector<int> len, cnt;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t = lz = sum = vector<ll>(4 * n, 0);
        len = cnt = vector<int>(4 * n, 0);
    }

    void Build(int v, int l, int r, int a[])
    {
        sum[v] = 1LL * r * (r + 1) / 2 - 1LL * (l - 1) * l / 2;
        len[v] = r - l + 1;

        if (l == r)
        {
            t[v] = a[l];
            return;
        }

        int mid = l + r >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1 | 1, mid + 1, r, a);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += 1LL * len[u] * lz[v];
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }

        if (cnt[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += sum[u] * cnt[v];
                cnt[u] += cnt[v];
            }

            cnt[v] = 0;
        }
    }

    void Update(int v, int l, int r, int &left, int &right, int &val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            if (val == 1)
            {
                t[v] += sum[v];
                cnt[v]++;
                return;
            }
            else
            {
                t[v] += 1LL * len[v] * val;
                lz[v] += val;
                return;
            }
        }

        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    ll Get(int v, int l, int r, int &left, int &right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        ll val1 = Get(v << 1, l, mid, left, right);
        ll val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return val1 + val2;
    }

    void Update(int l, int r, int val) { Update(1, 1, n, l, r, val); }
    ll Get(int l, int r) { return Get(1, 1, n, l, r); }
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

    it = SegmentTree(n);
    it.Build(1, 1, n, a);

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1)
        {
            it.Update(l, r, 1 - l);
            it.Update(l, r, 1);
        }
        else cout << it.Get(l, r) << '\n';
    }

    return 0;
}