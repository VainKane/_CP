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
int const MOD = 1e9 + 7;
int const INV2 = 500000004;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

int Si(int n) { return (1LL * n * (n + 1) / 2) % MOD; }
int Sii(int n) { return (1LL * n * (n + 1) * (n + 2) / 3 - Si(n) + MOD) % MOD; }

struct Node
{
    int s, is, iis, p;
    Node(int _s = 0, int _is = 0, int _iis = 0, int _p = 1) { s = _s, is = _is, iis = _iis, p = _p; }
    
    int operator ()(int d1, int d2) const
    {
        int tmp = (1LL * d1 * is + 1LL * d2 * s - iis) % MOD;
        return 1LL * p * INV2 % MOD * (tmp + MOD) % MOD;
    }
};

Node Merge(Node a, Node b){ return Node((a.s + b.s) % MOD, (a.is + b.is) % MOD, (a.iis + b.iis) % MOD, 1LL * a.p * b.p % MOD); }

Node Val(int val, int l, int r)
{
    int si = Si(r) - Si(l - 1);
    int sii = Sii(r) - Sii(l - 1);
    int len = r - l + 1;

    return Node(1LL * len * val % MOD, 1LL * si * val % MOD, 1LL * sii * val % MOD, PowMod(val + 1, len));
}

struct SegmentTree
{
    vector<Node> t;
    vector<int> lz;
    int n;

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v] = Val(a[l], l, r);
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
        t.assign(4 * n, Node());
        lz.assign(4 * n, -1);
        if (n) Build(1, 1, n, a);
    }

    void Lazy(int v, int l, int r)
    {
        int mid = l + r >> 1;

        if (lz[v] != -1)
        {
            t[v << 1] = Val(lz[v], l, mid);
            lz[v << 1] = lz[v];

            t[v << 1 | 1] = Val(lz[v], mid + 1, r);
            lz[v << 1 | 1] = lz[v];

            lz[v] = -1;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = Val(val, l, r);
            lz[v] = val;
            return;
        }

        int mid = l + r >> 1;
        Lazy(v, l, r);

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    Node Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return Node();
        if (left <= l && right >= r) return t[v];

        Lazy(v, l, r);
        int mid = l + r >> 1;

        return Merge(Get(v << 1, l, mid, left, right), Get(v << 1 | 1, mid + 1, r, left, right));
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    Node Get(int l, int r)
    {
        if (l > r) return Node();
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
        int type, l, r, val;
        cin >> type >> l >> r;
        l++, r++;

        if (type == 1)
        {
            cin >> val;
            it.Update(l, r, val);
        }
        else
        {
            int k = r - l + 1;

            int d1 = k + 2 * l - 1;
            int d2 = (k - 1LL * l * k + l - 1LL * l * l) % MOD;
            if (d2 < MOD) d2 += MOD;

            cout << it.Get(l, r)(d1, d2) << '\n';
        }
    }

    return 0;
}