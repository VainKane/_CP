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
    vector<int> t;
    vector<int> lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                t[u] = lz[v];
                lz[u] = lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = val;
            lz[v] = val;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);
    }

    int Get(int v, int l, int r, int pos)
    {
        if (l == r) return t[v];

        Lazy(v);
        int mid = (l + r) >> 1;

        if (pos <= mid) return Get(2 * v, l, mid, pos);
        return Get(2 * v + 1, mid + 1, r, pos);
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Get(int pos)
    {
        return Get(1, 1, n, pos);
    }
};

int const N = 1e5 + 5;

int n;
int x1[N], x2[N], y[N];
SegmentTree it;

vector<int> vals;
vector<int> id[3 * N];

int GetId(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, n)
    {
        vals.push_back(x1[i]);
        vals.push_back(x2[i]);
        vals.push_back(y[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        x1[i] = GetId(x1[i]);
        x2[i] = GetId(x2[i]);
        y[i] = GetId(y[i]);

        id[y[i]].push_back(i);
    }

    it = SegmentTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x1[i] >> x2[i] >> y[i];

    Compress();

    long long res = 0;

    FOR(h, 1, sz(vals)) for (auto &i : id[h])
    {
        res += vals[h - 1] - it.Get(x1[i]);
        res += vals[h - 1] - it.Get(x2[i]);
        it.Update(x1[i], x2[i], vals[h - 1]);
    }

    cout << res;

    return 0;
}