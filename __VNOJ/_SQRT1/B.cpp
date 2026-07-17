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
int const BK = 447;
int const GR = N / BK + 5;
int bkId[N], bkL[GR], bkR[GR];

int cnt[GR];

int n, q;
int a[N];

void Init()
{
    FOR(i, 1, n)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

void Update(int l, int r)
{
    if (bkId[l] == bkId[r])
    {
        REP(i, (r - l + 1) / 2) swap(a[l + i], a[r - i]);
        return;
    }

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Init();

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
    }

    return 0;
}