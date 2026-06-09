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
double const oo = 1e9 + 9;
int const BK = 2; //447
int const GR = N / BK;
int bkId[N], bkL[GR], bkR[GR];

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

struct Segment
{
    double x, a, b;
    int id;

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }

    double Val()
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

    void Add(double a, double b, int id)
    {
        while (!seg.empty() && seg.back().Val() >= seg.back().x * a + b) seg.pop_back();

        if (seg.empty()) seg.push_back({-oo, a, b, id});
        else if (seg.back().a != a)
        {
            double x = (b - seg.back().b) / (seg.back().a - a);
            maxi(x, -oo); mini(x, oo);
            seg.push_back({x, a, b, id});
        }
    }

    pair<double, int> Get(int x)
    {
        if (seg.empty()) return {oo, 0};
        for (mini(id, sz(seg) - 1); id < sz(seg) && seg[id].x <= x; id++); id--;
        return {x * seg[id].a + seg[id].b, seg[id].id};
    }
};

int n;

int x[N], e[N];
vector<int> vals;

ConvexHullTrick cht;
ii b[N];

pair<double, int> res[N];

void Init()
{
    FOR(i, 1, n)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
    
    bkL[bkId[n] + 1] = oo;
}

void Compress()
{
    FOR(i, 1, n) vals.push_back(e[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) e[i] = lower_bound(all(vals), e[i]) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> e[i];

    Compress();
    Init();

    FOR(i, 1, n) res[i] = b[i] = {oo, 0};

    FOR(id, 1, bkId[n])
    {
        FOR(i, 1, bkR[id - 1]) mini(b[e[i]], {-x[i], i});
        FOR(i, 1, sz(vals)) if (b[i].S)
        {
            int e = vals[i - 1];
            cht.Add(1.0 / e, 1.0 * b[i].F / e, b[i].S);
        }

        FOR(i, bkL[id], bkR[id])
        {
            mini(res[i], cht.Get(x[i]));
            FOR(j, bkL[id], i - 1) mini(res[i], {(1.0 * x[i] - x[j]) / vals[e[j] - 1], j});
        }

        FOR(i, 1, bkR[id - 1]) b[e[i]] = {oo, 0};
        cht.Reset();
    }

    FORD(id, bkId[n], 1)
    {
        FOR(i, bkL[id + 1], n) mini(b[e[i]], {x[i], i});
        FOR(i, 1, sz(vals)) if (b[i].S)
        {
            int e = vals[i - 1];
            cht.Add(1.0 / e, 1.0 * b[i].F / e, b[i].S);
        }

        FOR(i, bkL[id], bkR[id])
        {
            mini(res[i], cht.Get(-x[i]));
            FOR(j, i + 1, bkR[id]) mini(res[i], {(1.0 * x[j] - x[i]) / vals[e[j] - 1], j});
        }

        FOR(i, bkL[id + 1], n) b[e[i]] = {oo, 0};
        cht.Reset();
    }

    FOR(i, 1, n)
    {
        int p = vals[e[res[i].S] - 1];
        int q = abs(x[i] - x[res[i].S]);
        int gcd = GCD(p, q);

        cout << p / gcd << ' ' << q / gcd << '\n';
    }

    return 0;
}