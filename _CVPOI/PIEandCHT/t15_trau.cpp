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
int const MOD = 1e9 + 7;
int const BK = 314;
int const LIM = 3 * BK;
int const GR = N / BK + 5;

int bkId[N], bkL[GR], bkR[GR];
double lg[N];

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

struct BullShit
{
    double val = -1;
    int b, c;

    BullShit(double _val = -1, int _b = 0, int _c = 0)
    {
        val = _val, b = _b, c = _c;
    }

    bool operator < (BullShit const other) const
    {
        return val < other.val;
    }

    int Val(int i)
    {
        return 1LL * b * PowMod(i, c) % MOD;
    }
};

struct Segment
{
    double x, a, b;
    int bb, cc;

    Segment(double _x = 0, double _a = 0, double _b = 0, int _bb = 0, int _cc = 0)
    {
        x = _x, a = _a, b = _b, bb = _bb, cc = _cc;
    }

    double Val()
    {
        return x * a + b;
    }

    bool operator < (Segment const other) const
    {
        return x < other.x;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;

    void Reset()
    {
        seg.clear();
    }
  
    void Add(int a, int bb)
    {
        double b = lg[bb];

        while (!seg.empty() && seg.back().Val() <= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back(Segment(-1, (double)a, b, bb, a));
        else if (a != seg.back().a) seg.push_back(Segment((b - seg.back().b) / (seg.back().a - a), (double)a, b, bb, a));
    }

    BullShit Get(double x)
    {
        if (seg.empty()) return BullShit();
        int id = upper_bound(all(seg), Segment(x)) - seg.begin() - 1;
        return BullShit(seg[id].a * x + seg[id].b, seg[id].bb, seg[id].cc);
    }
};

int n;
int a[N];

BullShit val[N];

vector<pair<int, int>> lines[GR];
ConvexHullTrick cht[GR];

void Init()
{
    FOR(i, 1, 1e5) lg[i] = log(i);
    FOR(i, 1, n)
    {
        int &id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

void Build(int id)
{
    sort(all(lines[id]));
    cht[id].Reset();

    for (auto &p : lines[id]) cht[id].Add(p.F, p.S);
    FOR(i, bkL[id], bkR[id]) maxi(val[i], cht[id].Get(lg[i]));
    lines[id].clear();
}

void Update(int l, int r, int b, int c)
{
    if (bkId[l] == bkId[r])
    {
        Build(bkId[l]);
        FOR(i, l, r) maxi(val[i], BullShit(lg[b] + c * lg[i], b, c));
        return;
    }

    FOR(id, bkId[l] + 1, bkId[r] - 1)
    {
        lines[id].push_back({c, b});
        if (sz(lines[id]) == LIM) Build(id);
    }

    Update(l, bkR[bkId[l]], b, c);
    Update(bkL[bkId[r]], r, b, c);
}

int Query(int i)
{
    Build(bkId[i]);
    if (val[i].val > lg[a[i]]) return val[i].Val(i);
    return a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int idx; cin >> idx;
            cout << Query(idx) << '\n';
        }
        else
        {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            Update(l, r, b, c);
        }
    }

    return 0;
}