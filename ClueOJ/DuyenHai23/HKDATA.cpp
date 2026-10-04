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
int const inf = 1e9 + 9;
ll const oo = 1e18;

ll Ceil(ll a, ll b) { return (a ^ b) < 0 ? a / b : (a + b - 1) / b; }

struct Query
{
    int l, r, c, id;
    void Input(int _id) { id = _id; cin >> l >> r >> c; }
    bool operator < (Query const other) const { return c < other.c; }
};

struct Segment
{
    int a;
    ll b, x;

    Segment(int _a = 0, ll _b = 0, ll _x = 0) { a = _a, b = _b, x = _x; }
    ll operator ()(ll x) { return a * x + b; }
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int idx = 0;

    void Add(int a, ll b)
    {
        while (!seg.empty() && seg.back()(seg.back().x) <= 1LL * seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({a, b, -inf});
        else if (seg.back().a != a) seg.push_back({a, b, Ceil(seg.back().b - b, a - seg.back().a)});
    }

    ll Get(int x)
    {
        mini(idx, sz(seg) - 1);
        while (idx + 1 < sz(seg) && seg[idx + 1].x <= x) idx++;
        return seg[idx](x);
    }
};

struct SegmentTree
{
    vector<ConvexHullTrick> t;
    int n, delta;

    SegmentTree(int _n = 0, int _delta = 0)
    {
        n = _n, delta = _delta;
        t.assign(4 * n, ConvexHullTrick());
    }

    void Build(int v, int l, int r, ll pre[])
    {
        if (delta == 1) FOR(i, l, r) t[v].Add(i, pre[i]);
        else FORD(i, r, l) t[v].Add(-i, -pre[i]);
        if (l == r) return;

        int mid = l + r >> 1;
        Build(v << 1, l, mid, pre);
        Build(v << 1 | 1, mid + 1, r, pre);
    }

    ll Get(int v, int l, int r, int &left, int &right, int x)
    {
        if (l > right || r < left) return -oo;
        if (left <= l && right >= r) return t[v].Get(x);

        int mid = l + r >> 1;
        ll val1 = Get(v << 1, l, mid, left, right, x);
        ll val2 = Get(v << 1 | 1, mid + 1, r, left, right, x);

        return max(val1, val2);
    }

    ll Get(int l, int r, int x) { return Get(1, 1, n, l, r, x); }
};

int n, q;
ll pre[N];

ll preMin[N], sufMin[N];
ll preMax[N], sufMax[N];

SegmentTree itMax, itMin;

Query qr[N];
ll res[N];

void Init()
{
    preMin[0] = sufMin[n + 1] = oo;
    preMax[0] = sufMax[n + 1] = -oo;

    FOR(i, 1, n)
    {
        preMin[i] = min(preMin[i - 1], pre[i]);
        preMax[i] = max(preMax[i - 1], pre[i]);
    }

    FORD(i, n, 1)
    {
        sufMin[i] = min(sufMin[i + 1], pre[i]);
        sufMax[i] = max(sufMax[i + 1], pre[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    FOR(i, 1, q) qr[i].Input(i);

    sort(qr + 1, qr + q + 1);
    Init();

    itMax = SegmentTree(n, 1);
    itMin = SegmentTree(n, -1);

    itMax.Build(1, 1, n, pre);
    itMin.Build(1, 1, n, pre);

    FOR(i, 1, q)
    {
        int l = qr[i].l, r = qr[i].r, c = qr[i].c;
        ll d = c * (1LL - l);
        ll k = c * (r - l + 1LL);

        ll mn = min({preMin[l - 1], -itMin.Get(l, r, c) + d, sufMin[r + 1] + k});
        ll mx = max({preMax[l - 1], itMax.Get(l, r, c) + d, sufMax[r + 1] + k});

        res[qr[i].id] = max(0LL, mx) - min(0LL, mn);
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}