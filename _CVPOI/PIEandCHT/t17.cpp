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

int const N = 1e5 + 5;
long long const oo = 1e9 + 9;

ll Ceil(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return (a < b) ? a / b : (a + b - 1) / b;
}

struct Segment
{
    ll x, a, b;

    Segment(ll _x = 0, ll _a = 0, ll _b = 0)
    {
        x = _x, a = _a, b = _b;
    }

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }

    ll Val()
    {
        return x * a + b;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;

    void Add(ll a, ll b)
    {
        while (!seg.empty() && seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({0, a, b});
        else if (seg.back().a != a)
        {
            ll x = Ceil(b - seg.back().b, seg.back().a - a);
            maxi(x, 0LL); mini(x, oo);
            seg.push_back({x, a, b});
        }
    }

    ll Get(int x)
    {
        int id = upper_bound(all(seg), Segment(x)) - seg.begin() - 1;
        return x * seg[id].a + seg[id].b;
    }
};

int n, m;
ConvexHullTrick cht;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cht.Add(-2 * x, 1LL * x * x + 1LL * y * y);
    }

    while (m--)
    {
        int x; cin >> x;
        cout << cht.Get(x) + 1LL * x * x << '\n';
    }

    return 0;
}