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

struct SegmentTree
{
    vector<pair<int, int>> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, {0, 0});
    }

    void Update(int v, int l, int r, int pos, pair<int, int> val)
    {
        if (l == r)
        {
            maxi(t[v], val);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    pair<int, int> Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return {0, 0};
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        auto p1 = Get(2 * v, l, mid, left, right);
        auto p2 = Get(2 * v + 1, mid + 1, r, left, right);

        return max(p1, p2);
    }

    void Update(int pos, pair<int, int> val)
    {
        Update(1, 1, n, pos, val);
    }

    pair<int, int> Get(int l, int r)
    {
        if (l > r) return {0, 0};
        return Get(1, 1, n, l, r);
    }
};

int const N = 1e5 + 5;

int n, d;

long long a[N];
SegmentTree it;

int trace[N];
vector<long long> vals;

int GetId(long long x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, n)
    {
        vals.push_back(a[i]);
        vals.push_back(a[i] - d);
        vals.push_back(a[i] + d);
    }

    sort(all(vals));
    it = SegmentTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    Compress();

    int ma = 0;
    int idx = 0;

    FOR(i, 1, n)
    {
        int id = GetId(a[i]);
        auto p = max(it.Get(1, GetId(a[i] - d)), it.Get(GetId(a[i] + d), it.n));
        auto cur = it.Get(id, id);
        cur.S = i;

        if (maxi(cur.F, p.F + 1))
        {
            trace[i] = p.S;
            it.Update(id, cur);
        }

        if (maxi(ma, cur.F)) idx = i;
    }

    vector<int> res;

    while (idx)
    {
        res.push_back(idx);
        idx = trace[idx];
    }

    reverse(all(res));

    cout << sz(res) << '\n';
    for (auto &i : res) cout << i << ' ';

    return 0;
}