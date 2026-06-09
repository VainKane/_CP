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
long long const oo = 1e6 + 3;

long long Ceil(long long a, long long b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    long long x, a, b;

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }

    long long Val()
    {
        return x * a + b;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;

    void Reset()
    {
        seg.clear();
    }

    void Add(long long a, long long b)
    {
        while (!seg.empty() && seg.back().Val() <= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({-oo, a, b});
        else if (a != seg.back().a)
        {
            long long x = Ceil(b - seg.back().b, seg.back().a - a);
            maxi(x, -oo), mini(x, oo);
            seg.push_back({x, a, b});
        }
    }

    long long Get(int x)
    {
        int id = upper_bound(all(seg), Segment{x}) - seg.begin() - 1;
        return x * seg[id].a + seg[id].b;
    }
} cht;

int n;

int a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    long long tmp = 0;
    FOR(i, 1, n)
    {
        cin >> a[i];
        
        pre[i] = pre[i - 1] + a[i];
        tmp += 1LL * i * a[i];
    }

    long long res = tmp;
    FOR(i, 1, n)
    {
        cht.Add(i - 1, -pre[i - 1]);
        maxi(res, tmp + cht.Get(a[i]) + pre[i] - 1LL * i * a[i]);
    }

    cht.Reset();
    FORD(i, n, 1)
    {
        cht.Add(-i, -pre[i]);
        maxi(res, tmp + cht.Get(-a[i]) + pre[i] - 1LL * i * a[i]);
    }

    cout << res;

    return 0;
}