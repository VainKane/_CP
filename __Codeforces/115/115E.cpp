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
    vector<long long> t;
    vector<long long> lz;
    int n;

    SegmentTree (int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                t[u] += lz[v];
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }
    }

    void UpdatePoint(int v, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            maxi(t[v], val);
            return;
        }

        int mid = (l + r) >> 1;
        
        if (pos <= mid) UpdatePoint(2 * v, l, mid, pos, val);
        else UpdatePoint(2 * v + 1, mid + 1, r, pos, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    void UpdateSegment(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += val;
            lz[v] += val;
            return;
        }

        Push(v);
        int mid = (l + r) >> 1;

        UpdateSegment(2 * v, l, mid, left, right, val);
        UpdateSegment(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    void UpdatePoint(int pos, long long val)
    {
        if (pos < 1 || pos > n) return;
        UpdatePoint(1, 1, n, pos, val);
    }

    void UpdateSegment(int l, int r, int val)
    {
        if (l > r) return;
        UpdateSegment(1, 1, n, l, r, val);
    }
};

int const N = 2e5 + 5;

int n, m;

long long pre[N];
vector<pair<int, int>> races[N];

SegmentTree it;
long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    FOR(i, 1, n)
    {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    while (m--)
    {
        int l, r, p;
        cin >> l >> r >> p;
        races[r].push_back({l, p});
    }

    it = SegmentTree(n + 1);

    FOR(i, 1, n)
    {
        for (auto &p : races[i]) it.UpdateSegment(1, p.F, p.S);
        dp[i] = max(dp[i - 1], it.t[1] - pre[i]);
        it.UpdatePoint(i + 1, dp[i] + pre[i]);
    }

    cout << dp[n];

    return 0;
}