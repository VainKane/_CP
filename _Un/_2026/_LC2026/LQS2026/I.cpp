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

int const N = 2e5 + 5;
ll const oo = 1e18 + 9;

struct SegmentTree
{
    vector<int> t, lz;
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

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (r < left || l > right) return;
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

    int Get(int v, int l, int r, int left, int right)
    {
        if (r < left || l > right) return n;
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = (l + r) >> 1;

        int m1 = Get(v << 1, l, mid, left, right);
        int m2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return min(m1, m2);
    }

    void Update(int l, int r, int val) { Update(1, 1, n, l, r, val); }
    int Get(int l, int r) { return Get(1, 1, n, l, r); }
};

int n, m, f;
int a[N], b[N];

ll l[N], r[N];
pair<ll, int> d[N];

int cnt[N];
SegmentTree it;

void Reset()
{
    memset(l, 0, (n + 1) * sizeof(ll));
    memset(r, 0, (n + 1) * sizeof(ll));
    it = SegmentTree(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> f;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m) cin >> b[i];

        Reset();

        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);

        int idx = 0;
        ll ma = -oo;

        FOR(i, 1, n)
        {
            cnt[i] = cnt[i - 1];
            while (idx < m && b[idx + 1] < a[i])
            {
                idx++;
                maxi(ma, -1LL * f * idx + 2 * b[idx]);
                cnt[i]++;
            }

            maxi(l[i], ma + 1LL * f * (cnt[i] + 1) - 2 * a[i]);
        }

        idx = m + 1, ma = -oo;
        FORD(i, n, 1)
        {
            while (idx > 1 && b[idx - 1] > a[i])
            {
                idx--;
                maxi(ma, 1LL * f * idx - 2 * b[idx]);
            }

            maxi(r[i], ma - 1LL * f * cnt[i] + 2 * a[i]);
        }

        FOR(i, 1, n) d[i].F = r[i] - a[i] + 1LL * f * cnt[i] - (l[i] + a[i] - 1LL * f * cnt[i]), d[i].S = i;
        sort(d + 1, d + n + 1, greater<pair<ll, int>>());

        int haha = 0;
        ll res = 0;

        FOR(i, 1, n)
        {
            res += l[i] + a[i] - 1LL * f * cnt[i];
            it.Update(i, i, i);
        }

        FOR(i, 1, n)
        {
            if (haha == n / 2) break;
            if (it.Get(d[i].S, n) >= 2)
            {
                it.Update(d[i].S, n, -2);
                res += d[i].F;
                haha++;
            }
        }

        cout << res << '\n';
    }

    return 0;
}