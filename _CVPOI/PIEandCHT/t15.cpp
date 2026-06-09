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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const BK = 317;
int const MOD = 1e9 + 7;

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

struct BullShit
{
    double val = -1;
    int b, c;

    bool operator < (BullShit const other) const
    {
        return val < other.val;
    }

    int Val(int i)
    {
        return 1LL * b * PowMod(i, c) % MOD;
    }
};

struct Node
{
    pair<int, int> p1, p2;

    Node(pair<int, int> _p1 = {0, 0}, pair<int, int> _p2 = {0, 0})
    {
        p1 = _p1, p2 = _p2;
    }
};

struct SegmentTree
{
    vector<Node> t;
    vector<pair<int, int>> lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, Node());
        lz.assign(4 * n, {0, 0});
    }

    Node Merge(Node a, Node b)
    {
        if (a.p1 > b.p1) return Node{a.p1, max(a.p2, b.p1)};
        return Node{b.p1, max(a.p1, b.p2)};
    }

    void Lazy(int v)
    {
        if (lz[v].F)
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] = Merge(t[u], {lz[v], {0, 0}});
                maxi(lz[u], lz[v]);
            }

            lz[v] = {0, 0};
        }
    }

    void Update(int v, int l, int r, int left, int right, pair<int, int> p)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = Merge(t[v], {p, {0, 0}});
            maxi(lz[v], p);
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        Update(v << 1, l, mid, left, right, p);
        Update(v << 1 | 1, mid + 1, r, left, right, p);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    Node Get(int v, int l, int r, int pos)
    {
        if (l == r) return t[v];

        Lazy(v);
        int mid = (l + r) >> 1;

        if (pos <= mid) return Get(v << 1, l, mid, pos);
        return Get(v << 1 | 1, mid + 1, r, pos);
    }

    void Update(int l, int r, pair<int, int> p)
    {
        if (l > r) return;
        return Update(1, 1, n, l, r, p);
    }

    Node Get(int pos)
    {
        return Get(1, 1, n, pos);
    }
};

int n;

int a[N];
double lg[N];
BullShit val[N];

SegmentTree it;

double Val(pair<int, int> p, int i)
{
    return lg[p.S] + p.F * lg[i];
}

int LightQuery(int i)
{
    if (val[i].val > lg[a[i]]) return val[i].Val(i);
    return a[i];
}

int HeavyQuery(int i)
{
    auto node = it.Get(i);
    auto p = Val(node.p1, i) > Val(node.p2, i) ? node.p1 : node.p2;

    if (Val(p, i) > lg[a[i]]) return 1LL * p.S * PowMod(i, p.F) % MOD;
    return a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, 1e5) lg[i] = log(i);
    it = SegmentTree(n);

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int idx; cin >> idx;
            if (idx <= BK) cout << LightQuery(idx) << '\n';
            else cout << HeavyQuery(idx) << '\n';
        }
        else
        {
            int l, r, b, c;
            cin >> l >> r >> b >> c;

            FOR(i, l, min(r, BK)) maxi(val[i], BullShit{Val({c, b}, i), b, c});
            it.Update(max(l, BK + 1), r, {c, b});
        }
    }

    return 0;
}