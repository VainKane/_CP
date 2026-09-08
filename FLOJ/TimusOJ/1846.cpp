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
int const BK = 314;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

vector<int> vals;
int cnt[N];

int n, q;
pair<char, int> qr[N];

bool mark[N];
int cnt0[N];

vector<int> v;

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

void Init()
{
    FOR(i, 1, q)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

void Compress()
{
    FOR(i, 1, q) vals.push_back(qr[i].S);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, q) qr[i].S = lower_bound(all(vals), qr[i].S) - vals.begin() + 1;
    n = sz(vals);
}

int GetGCD(int l, int r, bool reset = true, int res = 0)
{
    if (l > r) return 0;
    FOR(i, l, r) cnt[qr[i].S] += qr[i].F == '+' ? 1 : -1;
    
    FOR(i, l, r) if (cnt[qr[i].S] + cnt0[qr[i].S] && !mark[qr[i].S]) res = GCD(res, vals[qr[i].S - 1]);
    for (auto &x : v) if (cnt[x] + cnt0[x]) res = GCD(res, vals[x - 1]);
    
    if (reset) FOR(i, l, r) cnt[qr[i].S] = 0;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> q;
    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    Init();
    Compress();

    FOR(id, 1, bkId[q])
    {
        memset(cnt0, 0, sizeof cnt);
        v.clear();

        FOR(i, bkL[id], bkR[id]) if (qr[i].F == '-') mark[qr[i].S] = true;
        int gcd = GetGCD(1, bkR[id - 1], false);

        FOR(i, bkL[id], bkR[id]) if (qr[i].F == '-') v.push_back(qr[i].S);
        memset(mark, false, sizeof mark);

        FOR(i, 1, n)
        {
            cnt0[i] = cnt[i];
            cnt[i] = 0;
        }

        FOR(i, bkL[id], bkR[id]) 
        {
            int res = GetGCD(bkL[id], i, true, gcd);
            if (res == 0) res = 1;
            cout << res << '\n';
        }
    }

    return 0;
}