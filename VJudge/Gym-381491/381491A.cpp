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
int const oo = 1e9;

int Ceil(int a, int b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    int x, a, b;

    Segment(int _x = 0, int _a = 0, int _b = 0)
    {
        x = _x, a = _a, b = _b;
    }

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;

    void Add(int a, int b)
    {
        while (!seg.empty())
        {
            int x = seg.back().x;
            if (1LL * x * seg.back().a + seg.back().b <= 1LL * x * a + b) seg.pop_back();
            else break;
        }

        if (seg.empty()) seg.push_back({-oo, a, b});
        else
        {
            if (a == seg.back().a) return;
            else seg.push_back({Ceil(seg.back().b - b, a - seg.back().a), a, b});
        }
    }

    long long Get(int x)
    {
        int id = upper_bound(all(seg), Segment(x, 0, 0)) - seg.begin() - 1;
        return 1LL * x * seg[id].a + seg[id].b;
    }
} cht;

int n;
pair<int, int> p[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> p[i].F >> p[i].S;

    sort(p + 1, p + n + 1);
    FOR(i, 1, n) cht.Add(p[i].F, p[i].S);

    int q; cin >> q;
    while (q--)
    {
        int x; cin >> x;
        cout << cht.Get(x) << '\n';
    }

    return 0;
}