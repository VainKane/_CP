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
int const oo = 101;

int Ceil(int a, int b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    int x, a, b;

    int Val()
    {
        return a * x + b;
    }        
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int id = 0;

    void Add(int a, int b)
    {
        while (!seg.empty())
        {
            if (seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
            else break;
        }

        if (seg.empty()) seg.push_back({-oo, a, b});
        else
        {
            if (a == seg.back().a) return;
            else seg.push_back({Ceil(seg.back().b - b, a - seg.back().a), a, b});
        }
    }

    int Get(int x)
    {
        mini(id, sz(seg) - 1);
        for (; id < sz(seg) && seg[id].x <= x; id++);
        id--;

        return x * seg[id].a + seg[id].b;
    }
} cht;

int n;

int dp[N];
int a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> dp[1];
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n)
    {
        cht.Add(b[i], dp[i]);
        dp[i + 1] = cht.Get(a[i + 1]);
    }

    cout << dp[n];

    return 0;
}