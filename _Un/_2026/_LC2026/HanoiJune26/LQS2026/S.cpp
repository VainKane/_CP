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

int const N = 2009;

struct SegmentTree
{
    vector<int> t, minSuf;
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
            t[v] += val, minSuf[v] += val;
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = t[v << 1] + t[v << 1 | 1];
        minSuf[v] = min(minSuf[v << 1] + t[v << 1 | 1], minSuf[v << 1 | 1]);
    }

    void Update(int pos, int val) { if (pos >= 1 && pos <= n) Update(1, 1, n, pos, val); }
};

int m, n, k;

int h[N];
int a[N][N];

int maxH[N];
ll pre[N];

SegmentTree it;
vector<int> vals;

void Compress()
{
    FOR(i, 1, m) FOR(j, 1, n) vals.push_back(a[i][j]);
    FOR(i, 1, k) vals.push_back(h[i]);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    
    FOR(i, 1, m) FOR(j, 1, n) a[i][j] = lower_bound(all(vals), a[i][j]) - vals.begin() + 1;
    FOR(i, 1, k) h[i] = lower_bound(all(vals), h[i]) - vals.begin() + 1;
    it = SegmentTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    FOR(i, 1, k) cin >> h[i], h[i]--;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Compress();
    FOR(i, 1, k) it.Update(h[i], 1);
    int res = 0;

    FOR(i, 1, m)
    {
        FOR(j, 1, n) maxi(maxH[j], a[i - 1][j]), pre[j] = pre[j - 1] + vals[a[i][j] - 1];
        FOR(j, 1, k - 1) it.Update(maxH[j], -1);

        FOR(j, 1, n - k + 1)
        {
            it.Update(maxH[j - 1], 1);
            it.Update(maxH[j + k - 1], -1);
            res += it.minSuf[1] >= 0 && pre[j + k - 1] == pre[j - 1];
        }

        FOR(j, n - k + 1, n) it.Update(maxH[j], 1);
    }

    cout << res;

    return 0;
}