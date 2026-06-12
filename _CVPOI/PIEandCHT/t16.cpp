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
int const Q = 3e5 + 5;
ll const oo = 6e18;

struct Segment
{
    ll a, b;
    int id;

    Segment(ll _a = 0, ll _b = oo, int _id = -1) { a = _a, b = _b, id = _id; }
    ll operator ()(int x) { return x * a + b; }
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
};

int n, q;

int t[N], v[N];
ii qr[Q];

int id[N], res[Q];

vector<int> vals;
LichaoTree lct;

void Compress()
{
    FOR(i, 1, q) vals.push_back(qr[i].F);
    FOR(i, 1, q) qr[i].F = lower_bound(all(vals), qr[i].F) - vals.begin() + 1;
    lct = LichaoTree(vals);
}

bool cmp(int i, int j) { return t[i] < t[j]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> t[id[i] = i] >> v[i], v[i] = abs(v[i]);
    FOR(i, 1, q) cin >> qr[i].F, qr[i].S = i;

    sort(qr + 1, qr + q + 1);
    sort(id + 1, id + n + 1, cmp);

    Compress();

    int idx = 1;
    FOR(i, 1, q)
    {
        for (; idx <= n && t[id[idx]] <= vals[qr[i].F - 1]; idx++)
        {
            int k = id[idx];
            lct.Add({v[k], -1LL * v[k] * t[k], k});
        }

        res[qr[i].S] = lct.Get(qr[i].F).id;
    }

    FOR(i, 1, q) cout << res[i] << ' ';

    return 0;
}