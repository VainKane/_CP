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
ll const oo = 1e18 + 9;

void GetEqt(ii x, ii y, int &a, int &b, ll &c)
{
    a = x.S - y.S;
    b = y.F - x.F;
    c = -1LL * a * x.F -1LL * b * x.S;
}

struct Segment
{
    double a, b;

    Segment(double _a = 0, double _b = -oo) { a = _a, b = _b; }
    double operator ()(int x) { return x * a + b; }
};

struct LichaoTree
{
    vector<Segment> t;
    int n;

    LichaoTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, Segment());
    }

    void Add(int v, int l, int r, Segment seg)
    {
        if (l == r)
        {
            if (seg(l) > t[v](l)) t[v] = seg;
            return;
        }

        int mid = (l + r) >> 1;
        if (seg.a > t[v].a) swap(seg, t[v]);

        if (t[v](mid) < seg(mid))
        {
            swap(seg, t[v]);
            Add(v << 1 | 1, mid + 1, r, seg);
        }
        else Add(v << 1, l, mid, seg);
    }

    double Get(int v, int l, int r, int pos)
    {
        if (l == r) return t[v](pos);

        int mid = (l + r) >> 1;
        double val = pos <= mid ? Get(v << 1, l, mid, pos) : Get(v << 1 | 1, mid + 1, r, pos);
        return max(val, t[v](pos));
    }

    void Add(Segment seg) { Add(1, 1, n, seg); }
    double Get(int pos) { return Get(1, 1, n, pos); }
    void Reset() { t.assign(4 * n, Segment()); }
};

int n;

int h[N];
double val[N];

LichaoTree lct;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i];

    lct = LichaoTree(n);

    FOR(i, 1, n)
    {
        int a, b;
        ll c;

        FOR(j, 1, i - 1)
        {
            GetEqt({i, h[i]}, {j, h[j]}, a, b, c);
            lct.Add({-1.0 * a / b, -1.0 * c / b});
        }
        maxi(val[i], lct.Get(i));
    }

    lct.Reset();

    FORD(i, n, 1)
    {
        int a, b;
        ll c;

        FOR(j, i + 1, n)
        {
            GetEqt({i, h[i]}, {j, h[j]}, a, b, c);
            lct.Add({-1.0 * a / b, -1.0 * c / b});
        }
        maxi(val[i], lct.Get(i));
    }

    FOR(i, 1, n) cout << (ll)(val[i] - h[i]) << ' ';

    return 0;
}