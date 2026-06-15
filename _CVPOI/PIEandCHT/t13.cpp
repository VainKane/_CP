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

int const N = 1e6 + 5;
ll const oo = 1e6 + 5;

ll Ceil(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    ll x, a, b;
    int id;

    Segment(ll _x = 0, ll _a = 0, ll _b = 0, int _id = 0) { x = _x, a = _a, b = _b, id = _id; }
    ll operator ()() const { return x * a + b; }
    ll operator ()(int x) { return x * a + b; }
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int id = 0;

    ConvexHullTrick() { seg.clear(); id = 0; }

    void Add(ll a, ll b, int id)
    {
        while (!seg.empty() && seg.back()() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({-oo, a, b, id});
        else if (seg.back().a != a)
        {
            ll x = Ceil(b - seg.back().b, seg.back().a - a);
            maxi(x, -oo); mini(x, oo);
            seg.push_back({x, a, b, id});
        }
    }

    pair<ll, int> Get(int x)
    {
        if (seg.empty()) return {1e18, 0};
        for (mini(id, sz(seg) - 1); id < sz(seg) && seg[id].x <= x; id++); id--;
        return {seg[id](x), seg[id].id};
    }
};

int n, q, a;

int v[N];
ll pre[N];

namespace Sub5
{
    bool CheckSub() { return n <= 5e4; }

    int const N = 5e4 + 5;
    int const BK = 223;
    int const GR = N / BK + 5;
    int bkId[N], bkL[GR], bkR[GR];

    ConvexHullTrick maxIn[GR], minIn[GR];
    ConvexHullTrick minOut[GR];
    
    pair<int, ll> p[N];
    bool mark[N];

    ll sA = 0, sB = 0;
    ll res[N];

    void Build(int id)
    {
        minIn[id] = maxIn[id] = minOut[id] = ConvexHullTrick();

        FOR(i, bkL[id], bkR[id])
        {
            if (mark[i]) minIn[id].Add(-p[i].F, p[i].S, i);
            else minOut[id].Add(-p[i].F, p[i].S, i);
        }

        FORD(i, bkR[id], bkL[id]) if (mark[i]) maxIn[id].Add(p[i].F, -p[i].S, i); 
    }

    int GetLine(int k, ConvexHullTrick cht[])
    {
        pair<ll, int> res = {1e18, 0};
        FOR(id, 1, bkId[n]) mini(res, cht[id].Get(k));
        return res.S;
    }

    void Init()
    {
        FOR(i, 1, n)
        {
            p[i].F = v[i];
            p[i].S = 1LL * i * v[i] + 1LL * a * v[i] + pre[i - 1];
        }

        sort(p + 1, p + n + 1);
        FOR(i, 1, n)
        {
            int id = bkId[i] = (i - 1) / BK + 1;
            if (!bkL[id]) bkL[id] = i;
            bkR[id] = i;
        }

        FOR(id, 1, bkId[n]) Build(id);
    }

    void Add(int idx, int delta)
    {
        sA += delta * p[idx].F;
        sB += delta * p[idx].S;
    }

    void Process()
    {
        Init();

        FOR(k, 1, n)
        {
            auto idx = GetLine(k, minOut);
            Add(idx, 1);
            mark[idx] = 1;

            Build(bkId[idx]);
            
            while (true)
            {
                int i = GetLine(k, maxIn);
                int j = GetLine(k, minOut);

                if (i == 0 || j == 0) break;
                if (-1LL * k * p[i].F + p[i].S > -1LL * k * p[j].F + p[j].S)
                {
                    Add(i, -1), Add(j, 1);
                    swap(mark[i], mark[j]);
                    Build(bkId[i]), Build(bkId[j]);
                }
                else break;
            }

            res[k] = -k * sA + sB;
        }

        while (q--)
        {
            int idx; cin >> idx;
            cout << res[idx] << '\n';
        }
    }
}

namespace Sub3
{
    bool CheckSub() { return q == 1; }
    long long c[N];

    void Process()
    {
        while (q--)
        {
            int r; cin >> r;
            FOR(i, 1, n) c[i] = 1LL * a * v[i] + pre[i - 1] + 1LL * v[i] * (i - r);

            sort(c + 1, c + n + 1);

            long long res = 0;
            FOR(i, 1, r) res += c[i];
            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q >> a;
    FOR(i, 1, n) cin >> v[i], pre[i] = pre[i - 1] + v[i];

    if (Sub3::CheckSub()) return Sub3::Process(), 0;
    if (Sub5::CheckSub()) return Sub5::Process(), 0;

    return 0;
}