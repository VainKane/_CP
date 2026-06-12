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
int const oo = 1e9 + 9;

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

struct Segment
{
    double a, b;
    int id;

    Segment(double _a = oo, double _b = oo, int _id = 0) { a = _a, b = _b, id = _id; }
    double operator ()(int x) const { return x * a + b; }
};

struct LichaoTree
{
    vector<Segment> t;
    vector<int> vals;
    int n;

    LichaoTree(vector<int> _vals = {})
    {
        vals = _vals;
        n = sz(vals);
        t.assign(4 * n, Segment());
    }

    void Add(int v, int l, int r, Segment seg)
    {
        if (l == r)
        {
            if (seg(vals[l - 1]) < t[v](vals[l - 1])) t[v] = seg;
            return;
        }
    
        int mid = (l + r) >> 1;
        if (seg.a < t[v].a) swap(seg, t[v]);

        if (t[v](vals[mid - 1]) < seg(vals[mid - 1])) Add(v << 1, l, mid, seg);
        else
        {
            swap(t[v], seg);
            Add(v << 1 | 1, mid + 1, r, seg);
        }
    }

    Segment Get(int v, int l, int r, int pos)
    {
        if (l == r) return t[v];
        int mid = (l + r) >> 1;

        auto seg = pos <= mid ? Get(v << 1, l, mid, pos) : Get(v << 1 | 1, mid + 1, r, pos);
        return seg(vals[pos - 1]) < t[v](vals[pos - 1]) ? seg : t[v];
    }

    void Add(Segment seg) { Add(1, 1, n, seg); }
    Segment Get(int pos) { return Get(1, 1, n, pos); }
    void Reset() { t.assign(4 * n, Segment()); }
};

int n;
int x[N], e[N];

LichaoTree lct;
Segment res[N];

vector<int> vals;

void Compress()
{
    FOR(i, 1, n) vals.push_back(x[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) x[i] = lower_bound(all(vals), x[i]) - vals.begin() + 1;
    lct = LichaoTree(vals);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> e[i];

    Compress();

    FOR(i, 1, n)
    {
        auto seg = lct.Get(x[i]);
        int pos = vals[x[i] - 1];
        if (seg(pos) < res[i](pos)) res[i] = seg;
        lct.Add({1.0 / e[i], -1.0 * pos / e[i], i});
    }

    lct.Reset();

    FORD(i, n, 1)
    {
        auto seg = lct.Get(x[i]);
        int pos = vals[x[i] - 1];
        if (seg(pos) < res[i](pos)) res[i] = seg;
        lct.Add({-1.0 / e[i], 1.0 * pos / e[i], i});
    }

    FOR(i, 1, n)
    {
        int id = res[i].id;
        int q = abs(vals[x[id] - 1] - vals[x[i] - 1]);
        int gcd = GCD(e[id], q);

        cout << e[id] / gcd << ' ' << q / gcd << '\n';
    }

    return 0;
}