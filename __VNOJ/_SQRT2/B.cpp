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

int const N = 3e5 + 5;
long long const oo = 1e18;
int const BK = 547;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

int Ceil(int a, int b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    int x, a, b;

    long long Val()
    {
        return 1LL * x * a + b;
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

    void Add(int a, int b)
    {
        while (!seg.empty())
        {
            int x = seg.back().x;
            if (seg.back().Val() <= 1LL * x * a + b) seg.pop_back();
            else break;
        }

        if (seg.empty()) seg.push_back({-(int)1e9, a, b});
        else
        {
            if (seg.back().a == a) return;
            seg.push_back({Ceil(b - seg.back().b, seg.back().a - a), a, b});
        }
    }

    long long Get(int x)
    {
        if (seg.empty()) return -oo;
        for (; id < sz(seg) && seg[id].x <= x; id++);
        id--;

        assert(id >= 0 && id < sz(seg));
        return 1LL * x * seg[id].a + seg[id].b;
    }
} cht;

int n;

int a[N], b[N];
pair<int, int> qr[N];

long long res[N];
bool mark[N], bkMark[N];

vector<int> vals;
vector<int> adj[N];

void Compress()
{
    FOR(i, 1, n) if (qr[i].F == 1) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) if (qr[i].F == 1) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
}

void Init()
{
    FOR(i, 1, n)
    {
        int &id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

bool cmp(int i, int j)
{
    return qr[i].S < qr[j].S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int t; cin >> t;
        if (t == 1) cin >> a[i] >> b[i], qr[i].F = 1;
        else if (t == 2) cin >> qr[i].S, qr[i].F = -1;
        else cin >> qr[i].S;
    }

    Compress();
    Init();

    memset(res, -0x3f, sizeof res);
    FOR(id, 1, bkId[n])
    {
        memset(mark, false, (bkR[id - 1] + 1) * sizeof(bool));
        memset(bkMark, false, sizeof bkMark);

        FOR(i, bkL[id], bkR[id]) if (qr[i].F == -1) bkMark[qr[i].S] = 1;
        FOR(i, 1, bkR[id - 1]) if (qr[i].F) mark[qr[i].F == 1 ? i : qr[i].S] ^= 1;

        FOR(i, 1, sz(vals)) adj[i].clear();
        cht.Reset();

        FOR(i, 1, bkR[id - 1]) if (qr[i].F == 1 && mark[i] && !bkMark[i]) adj[a[i]].push_back(b[i]);
        FOR(x, 1, sz(vals)) for (auto &y : adj[x]) cht.Add(vals[x - 1], y);

        vector<int> ids;
        FOR(i, bkL[id], bkR[id])
        {
            if (qr[i].F) mark[qr[i].F == 1 ? i : qr[i].S] ^= 1;
            else
            {
                ids.push_back(i);
                int x = qr[i].S;

                FOR(j, bkL[id], i - 1) if (qr[j].F == 1 && mark[j]) maxi(res[i], 1LL * vals[a[j] - 1] * x + b[j]);
                FOR(j, i + 1, bkR[id]) if (qr[j].F == -1 && mark[qr[j].S])
                {
                    int idx = qr[j].S;
                    maxi(res[i], 1LL * vals[a[idx] - 1] * x + b[idx]);
                }
            }
        }

        sort(all(ids), cmp);
        for (auto &i : ids) maxi(res[i], cht.Get(qr[i].S));
    }

    FOR(i, 1, n) if (!qr[i].F)
    {
        if (res[i] <= -oo) cout << "EMPTY SET\n";
        else cout << res[i] << '\n';
    }

    return 0;
}