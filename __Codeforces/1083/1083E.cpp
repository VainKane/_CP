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

int const N = 1e6 + 5;
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
        if (seg.empty()) return 0;
        for (mini(id, sz(seg) - 1); id < sz(seg) && seg[id].x <= x; id++);
        id--;
        return x * seg[id].a + seg[id].b;
    }
} cht;

int n;

int x[N], y[N];
long long a[N];
int id[N];

bool cmp(int i, int j)
{
    return x[i] < x[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i] >> a[id[i] = i];

    sort(id + 1, id + n + 1, cmp);
    long long res = 0;

    FOR(i, 0, n)
    {
        int idx = id[i];
        long long dp = cht.Get(-y[idx]) + 1LL * x[idx] * y[idx] - a[idx];
        cht.Add(x[idx], dp);
        maxi(res, dp);
    }

    cout << res;

    return 0;
}