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

int const N = 1e5 + 5;

struct SegmentTree
{
    vector<int> t, lz;
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

        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        if (n) Build(1, 1, n, a);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += lz[v];
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
            t[v] += val;
            lz[v] += val;
            return;
        }
    
        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return N;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        return min(Get(v << 1, l, mid, left, right), Get(v << 1 | 1, mid + 1, r, left, right));
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return N;
        return Get(1, 1, n, l, r);
    }
};

int n, m;

int c[N];
ii a[N];

SegmentTree it;

bool cmp(ii a, ii b) { return a.S < b.S; }

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, m) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + m + 1, cmp);
    it = SegmentTree(n, c);

    int res = 0;
    FOR(i, 1, m) if (it.Get(a[i].F, a[i].S)) it.Update(a[i].F, a[i].S, -1), res++;
    cout << res;

    return 0;
}