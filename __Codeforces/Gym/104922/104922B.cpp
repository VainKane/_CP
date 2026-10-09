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

#pragma GCC optimize("O2,O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

struct SegmentTree
{
    vector<ll> t;
    vector<int> len, lz;
    int n;

    void Build(int v, int l, int r, int a[])
    {
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

    SegmentTree(int _n = -1, int a[] = {})
    {
        n = _n;

        t.assign(MK(n + 1), 0);
        lz.assign(MK(n + 1), -1);
        len.assign(MK(n + 1), 0);
        
        if (n != -1) Build(1, 0, MK(n) - 1, a);
    }

    void Lazy(int v)
    {
        if (lz[v] != -1)
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] = 1LL * len[u] * lz[v];
                lz[u] = lz[v];
            }

            lz[v] = -1;
        }
    }

    void Update(int v, int l, int r, int left, int right, int k, int val, int i)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = 1LL * len[v] * val;
            lz[v] = val;
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        Update((v << 1) ^ BIT(i, k), l, mid, left, right, k, val, i - 1);
        Update((v << 1 | 1) ^ BIT(i, k), mid + 1, r, left, right, k, val, i - 1);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    ll Get(int v, int l, int r, int left, int right, int k, int i)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        ll val1 = Get((v << 1) ^ BIT(i, k), l, mid, left, right, k, i - 1);
        ll val2 = Get((v << 1 | 1) ^ BIT(i, k), mid + 1, r, left, right, k, i - 1);

        return val1 + val2;
    }

    void Update(int l, int r, int k, int val) { Update(1, 0, MK(n) - 1, l, r, k, val, n - 1); }
    ll Get(int l, int r, int k) { return Get(1, 0, MK(n) - 1, l, r, k, n - 1); }
};

int n, q;

int a[MK(20) + 5];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, MK(n)) cin >> a[i];

    it = SegmentTree(n, a);

    int type, l, r, k, val;

    int q; cin >> q;
    while (q--)
    {
        cin >> type >> l >> r >> k;

        if (type == 1)
        {
            cin >> val;
            it.Update(l, r, k, val);
        }
        else cout << it.Get(l, r, k) << '\n';
    }

    return 0;
}