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
int const oo = 2e9 + 9;

struct Data
{
    int l, r, p;
    void Input() { cin >> l >> r >> p; }
    bool operator < (Data const other) { return l < other.l; }
};

struct SegmentTree
{
    vector<int> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, oo);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            mini(t[v], val);
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    int Get(int v, int l, int r, int left, int right, int x)
    {
        if (l > right || r < left || t[v] > x) return oo;
        if (l == r) return l;

        int mid = l + r >> 1;

        int pos = Get(v << 1, l, mid, left, right, x);
        if (pos != oo) return pos;
        return Get(v << 1 | 1, mid + 1, r, left, right, x);
    }

    void Update(int pos, int val) { Update(1, 1, n, pos, val); }

    int Get(int l, int r, int x)
    {
        if (l > r) return oo;
        return Get(1, 1, n, l, r, x);
    }
};

int n, m;

Data a[N];
SegmentTree it;

int l1[N];

vector<int> vals;
vector<int> idx[3 * N];
bool mark[3 * N];

#define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1)

void Compress()
{
    vals.push_back(0);
    vals.push_back(m);

    FOR(i, 1, n)
    {
        vals.push_back(a[i].r);
        vals.push_back(a[i].l);
        vals.push_back(a[i].l - 1);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        a[i].r = GetId(a[i].r);
        l1[i] = GetId(a[i].l - 1);
        a[i].l = GetId(a[i].l);
    }
}

bool Check(int k)
{
    memset(mark, false, sizeof mark);
    mark[1] = true;

    it = SegmentTree(sz(vals));
    FOR(i, 1, n) idx[a[i].r].clear();

    int j = 1;
    FOR(i, 1, n) if (a[i].p <= k)
    {
        for (; j < a[i].l; j++) for (auto &id : idx[j]) it.Update(a[id].r, a[id].p);

        int id = it.Get(a[i].l, a[i].r, k - a[i].p);
        if (mark[l1[i]]) id = l1[i];

        if (id < oo)
        {
            if (id < a[i].l) it.Update(a[i].r, a[i].p);
            else idx[id].push_back(i);

            mark[a[i].r] = true;
            if (a[i].r == m) return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) a[i].Input();

    sort(a + 1, a + n + 1);
    Compress();
    m = GetId(m);

    int l = 1, r = oo;
    int res = r;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (Check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << (res < oo ? res : -1);

    return 0;
}