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

int const N = 2e5 + 5;
int const oo = 1e6 + 7;

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

    void Add(long long a, long long b)
    {
        while (!seg.empty() && seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({-oo, a, b});
        else
        {
            if (a == seg.back().a) return;
            seg.push_back({Ceil(b - seg.back().b, seg.back().a - a), a, b});
        }
    }

    long long Get(int x)
    {
        for (mini(id, sz(seg)); id < sz(seg) && seg[id].x <= x; id++);
        id--;
        return x * seg[id].a + seg[id].b;
    }
} cht;

int n;
long long c;

int h[N];
long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    FOR(i, 1, n) cin >> h[i];

    FOR(i, 1, n)
    {
        cht.Add(-2 * h[i], 1LL * h[i] * h[i] + dp[i]);
        dp[i + 1] = cht.Get(h[i + 1]) + 1LL * h[i + 1] * h[i + 1] + c;
    }

    cout << dp[n];

    return 0;
}