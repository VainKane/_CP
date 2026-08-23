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

int const N = 5e5 + 5;
int const oo = 1e9 + 9;
ll const inf = 1e18 + 9;

struct SegmentTree
{
    vector<ll> t, lz;
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
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += lz[v];
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, ll val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += val;
            lz[v] += val;
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    ll Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return -inf;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = l + r >> 1;

        ll m1 = Get(v << 1, l, mid, left, right);
        ll m2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return max(m1, m2);
    }

    void Update(int l, int r, ll val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }
    
    ll Get(int l, int r)
    {
        if (l > r) return -inf;
        return Get(1, 1, n, l, r);
    }
};

struct SegmentTreeWalk
{
    vector<ll> t, lz;
    int n;

    SegmentTreeWalk(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += lz[v];
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, ll val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += val;
            lz[v] += val;
            return;
        }

        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    int Search(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left || t[v] >= 0) return 0;
        if (l == r) return l;

        Lazy(v);
        int mid = l + r >> 1;

        int pos = Search(v << 1, l, mid, left, right);
        if (pos) return pos;

        return Search(v << 1 | 1, mid + 1, r, left, right);
    }

    void Update(int l, int r, ll val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Search(int l, int r)
    {
        if (l > r) return 0;
        return Search(1, 1, n, l, r);
    }
};

int n, m, k, x;

int h[N], r[N];
int c[N], id[N];

ii a[N];
ll dp[N];

ll pre[N];
SegmentTree it;
SegmentTreeWalk itw;

bool cmp(int i, int j) { return h[i] > h[j]; }

void Init()
{
    sort(a + 1, a + m + 1, greater<ii>());
    sort(id + 1, id + n + 1, cmp);

    int idx = 0;
    int mi = oo;

    FOR(i, 1, n)
    {
        while (idx < m && a[idx + 1].F >= h[id[i]]) mini(mi, a[++idx].S);
        c[id[i]] = mi;
        pre[i] = pre[i - 1] + r[i];
    }
}

bool Solve()
{
    memset(dp, -1, sizeof dp);

    it = SegmentTree(n + 1);
    itw = SegmentTreeWalk(n + 1);

    if (x < c[1]) return false;
    it.Update(1, 1, x - c[1]);
    itw.Update(1, 1, x - c[1]);

    vector<int> pos;
    FOR(i, 1, n)
    {
        while (!pos.empty() && h[pos.back()] <= h[i])
        {
            int j = pos.back(); pos.pop_back();
            int idx = pos.empty() ? -1 : pos.back();
        }

        int idx = itw.Search(1, n + 1);
        while (idx)
        {
            it.Update(idx, idx, -inf);
            itw.Update(idx, idx, inf);
            idx = itw.Search(1, n + 1);
        }

        pos.push_back(i);

        dp[i] = it.Get(max(i - k, 0) + 1, i) + pre[i];
        if (dp[i] < 0 || c[i] == oo) return false;

        it.Update(i + 1, i + 1, dp[i] - pre[i] - c[i + 1]);
        itw.Update(i + 1, i + 1, dp[i] - c[i + 1]);
    }

    return dp[n] >= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> x;
    FOR(i, 1, n) cin >> h[i] >> r[i], id[i] = i;
    FOR(i, 1, m) cin >> a[i].F >> a[i].S;

    Init();
    cout << (Solve() ? "Yes" : "No");

    return 0;
}