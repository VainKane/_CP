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
    vector<int> minSuf;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        minSuf.assign(4 * n, 0);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] += val;
            minSuf[v] += val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = t[v << 1] + t[v << 1 | 1];
        minSuf[v] = min(minSuf[v << 1 | 1], minSuf[v << 1] + t[v << 1 | 1]);
    }

    void Update(int pos, int val)
    {
        if (pos < 1 || pos > n) return;
        Update(1, 1, n, pos, val);
    }
};

int const N = 2009;

int n, m, k;
int a[N][N];

int maxH[N];
long long pre[N];

vector<int> h;
SegmentTree it;

vector<int> vals;

int GetId(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, m) FOR(j, 1, n) vals.push_back(a[i][j]);
    for (auto &x : h) vals.push_back(x);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, m) FOR(j, 1, n) a[i][j] = GetId(a[i][j]);
    for (auto &x : h) x = GetId(x);

    it = SegmentTree(sz(vals));    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    FOR(i, 1, k)
    {
        int x; cin >> x;
        h.push_back(x - 1);
    }

    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    sort(all(h));
    Compress();

    for (auto &x : h) it.Update(x, 1);
    int res = 0;

    FOR(i, 1, m) 
    {
        FOR(j, 1, n) pre[j] = pre[j - 1] + vals[a[i][j] - 1];
        FOR(j, 1, k - 1) it.Update(maxH[j], -1);

        FOR(j, 1, n - k + 1)
        {
            it.Update(maxH[j - 1], 1);
            it.Update(maxH[j + k - 1], -1);
            res += it.minSuf[1] >= 0 && pre[j + k - 1] - pre[j - 1] == 0;
        }

        FOR(j, n - k + 1, n) it.Update(maxH[j], 1);
        FOR(j, 1, n) maxi(maxH[j], a[i][j]);
    }

    cout << res;

    return 0;
}