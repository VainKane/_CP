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

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

struct SegmentTree
{
    vector<int> t, lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 1);
        lz.assign(4 * n, 1);
    }

    void Lazy(int v)
    {
        if (lz[v] != 1)
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] = LCM(t[u], lz[v]);
                lz[u] = LCM(lz[u], lz[v]);
            }

            lz[v] = 1;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = LCM(t[v], val);
            lz[v] = LCM(lz[v], val);
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = GCD(t[v << 1], t[v << 1 | 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        return GCD(Get(v << 1, l, mid, left, right), Get(v << 1 | 1, mid + 1, r, left, right));
    }

    void Update(int l, int r, int val) { Update(1, 1, n, l, r, val); }
    int Get(int l, int r) { return Get(1, 1, n, l, r); }
};

int n, m;

SegmentTree it;
int l[N], r[N], c[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    it = SegmentTree(n);
    FOR(i, 1, m)
    {
        cin >> l[i] >> r[i] >> c[i];
        it.Update(l[i], r[i], c[i]);
    }

    FOR(i, 1, m) if (it.Get(l[i], r[i]) != c[i])
    {
        cout << -1;
        return 0;
    }
    
    FOR(i, 1, n) cout << it.Get(i, i) << ' ';

    return 0;
}