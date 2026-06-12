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
double const eps = 1e-7;

struct Segment
{
    double x, a, b;

    Segment(double _x = 0, double _a = 0, double _b = 0) { x = _x, a = _a, b = _b; }
    double operator()() const { return x * a + b; }
    bool operator < (Segment const other) const { return x < other.x; }
};

struct Line
{
    double a, b;

    Line(double _a = 0, double _b = -oo) { a = _a, b = _b; }
    double operator ()(int x) const { return x * a + b; }
};

struct LichaoTree
{
    vector<Line> t;
    int n;

    LichaoTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, Line());
    }

    void Add(int v, int l, int r, Line seg)
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

    void Add(Line seg) { Add(1, 1, n, seg); }
    double Get(int pos) { return Get(1, 1, n, pos); }
    void Reset() { t.assign(4 * n, Line()); }
};

struct ConvexHullTrick
{
    vector<Segment> seg;

    void Add(double a, double b)
    {
        while (!seg.empty() && seg.back()() <= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({-1e9, a, b});
        else if (seg.back().a != a) seg.push_back({(b - seg.back().b) / (seg.back().a - a), a, b});
    }

    int Get(double x)
    {
        if (seg.empty()) return 0;
        int id = upper_bound(all(seg), Segment{x}) - seg.begin() - 1;
        return seg[id].a;
    }

    void Reset() { seg.clear(); }
};

int n;

int h[N];
double val[N];

LichaoTree lct;
ConvexHullTrick cht;

int GetIdx(int i, int delta)
{
    double l = -1e9, r = 1e9;
    int j = 0;

    REP(haha, 60)
    {
        double mid = (l + r) / 2;
        
        int idx = cht.Get(mid);
        double lmao = mid * idx - h[abs(idx)] + h[i] + delta * mid * i; 

        if (lmao >= 0) j = abs(idx), l = mid;
        else r = mid;
    }

    return j;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i];

    lct = LichaoTree(n);
    cht = ConvexHullTrick();

    FOR(i, 1, n)
    {
        int j = GetIdx(i, -1);
        cht.Add(i, -h[i]);

        if (!j) continue;

        double ba = (1.0 * h[i] - h[j]) / (i - j);
        lct.Add({ba, h[i] - i * ba});
        maxi(val[i], lct.Get(i));
    }

    lct.Reset();
    cht.Reset();

    FORD(i, n, 1)
    {
        int j = GetIdx(i, 1);
        cht.Add(-i, -h[i]);

        if (!j) continue;

        double ba = (1.0 * h[i] - h[j]) / (i - j);
        lct.Add({ba, h[i] - i * ba});
        maxi(val[i], lct.Get(i));
    }

    FOR(i, 1, n) cout << (ll)(val[i] - h[i]) << ' ';

    return 0;
}