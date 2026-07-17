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
long long const oo = 1e9 + 9;

long long Ceil(long long a, long long b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    long long x, a, b;

    long long Val()
    {
        return x * a + b;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int id = 0;

    void Reset()
    {
        seg.clear();
        id = 0;
    }

    void Add(long long a, long long b)
    {
        while (!seg.empty() && seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({-oo, a, b});
        else if (seg.back().a != a)
        {
            long long x = Ceil(b - seg.back().b, seg.back().a - a);
            mini(x, oo), maxi(x, -oo);
            seg.push_back({x, a, b});
        }
    }

    long long Get(int x)
    {
        assert(!seg.empty());
        for (mini(id, sz(seg) - 1); id < sz(seg) && seg[id].x <= x; id++);
        id--;
        return x * seg[id].a + seg[id].b;
    }
} cht;

int n, m, p;

int d[N];
int h[N], t[N];

int a[N];

long long pre[N];
long long dp[2][N];

void Init()
{
    FOR(i, 1, n) pre[i] = pre[i - 1] + d[i];
    FOR(i, 1, m) a[i] = t[i] - pre[h[i]];

    sort(a + 1, a + m + 1);
    FOR(i, 1, m) pre[i] = pre[i - 1] + a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    FOR(i, 2, n) cin >> d[i];
    FOR(i, 1, m) cin >> h[i] >> t[i];

    Init();

    bool cur = 1;

    memset(dp[cur], -1, sizeof dp[cur]);
    dp[cur][0] = 0;

    REP(haha, p)
    {
        cht.Reset();
        cur ^= 1;

        FOR(i, 1, m)
        {
            if (dp[cur ^ 1][i - 1] != -1) cht.Add(-i + 1, dp[cur ^ 1][i - 1] + pre[i - 1]);
            dp[cur][i] = cht.Get(a[i]) - pre[i] + 1LL * i * a[i];
        }
    }

    cout << dp[cur][m];

    return 0;
}