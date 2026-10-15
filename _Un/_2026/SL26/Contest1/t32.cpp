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
ll const oo = 1e18;

struct Query { int l, r, id; };

struct Node
{
    ll sum, pre, suf, mx;
    Node(ll _sum = 0, ll _pre = -oo, ll _suf = -oo, ll _mx = -oo) { sum = _sum, pre = _pre, suf = _suf, mx = _mx; }
};

Node Merge(Node a, Node b)
{
    ll mx = max({a.mx, b.mx, a.suf + b.pre});
    ll pre = max({a.pre, a.sum + b.pre});
    ll suf = max({b.suf, b.sum + a.suf});

    return {a.sum + b.sum, pre, suf, mx};
};

struct SegmentTree
{
    vector<Node> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, Node(0, 0, 0, 0));
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v].sum += val;
            t[v].pre = t[v].suf = t[v].mx = t[v].sum;
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    Node Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return Node();
        if (left <= l && right >= r) return t[v];

        int mid = l + r >> 1;

        Node v1 = Get(v << 1, l, mid, left, right);
        Node v2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return Merge(v1, v2);
    }

    void Update(int pos, int val) { Update(1, 1, n, pos, val); }
    Node Get(int l, int r)
    {
        if (l > r) return Node();
        return Get(1, 1, n, l, r);
    }
};

int n, m, q;

vector<ii> events[N];
vector<Query> queries[N];

SegmentTree it;

int res[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int l, r, x;
        cin >> l >> r >> x;

        events[l].push_back({i, x});
        events[r + 1].push_back({i, -x});
    }

    cin >> q;
    FOR(i, 1, q)
    {
        int idx, l, r;
        cin >> idx >> l >> r;
        queries[idx].push_back({l, r, i});
    }
    
    it = SegmentTree(m);

    FOR(i, 1, n)
    {
        for (auto &e : events[i]) it.Update(e.F, e.S);
        for (auto &qr : queries[i]) res[qr.id] = it.Get(qr.l, qr.r).mx;
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}