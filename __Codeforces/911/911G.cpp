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
int const BK = 2000;
int bkId[N];

int n;
int a[N];

int lz[N / BK + 5][109];

void Init()
{
    REP(i, n) bkId[i] = i / BK;
    REP(i, BK) FOR(x, 1, 100) lz[i][x] = x;
}

void Lazy(int &id)
{
    FOR(i, id * BK, min(n, (id + 1) * BK - 1)) a[i] = lz[id][a[i]];
    FOR(x, 1, 100) lz[id][x] = x;
}

void ManualUpdate(int l, int r, int &x, int &y)
{
    Lazy(bkId[l]);
    FOR(i, l, r) if (a[i] == x) a[i] = y;
}

void Update(int &l, int &r, int &x, int &y)
{
    if (bkId[l] == bkId[r])
    {
        ManualUpdate(l, r, x, y);
        return;
    }

    FOR(i, bkId[l] + 1, bkId[r] - 1) FOR(val, 1, 100) if (lz[i][val] == x) lz[i][val] = y;
    ManualUpdate(l, (bkId[l] + 1) * BK - 1, x, y);
    ManualUpdate(bkId[r] * BK, r, x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> a[i];

    Init();

    int q; cin >> q;
    while (q--)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--, r--;
        Update(l, r, x, y);
    }

    REP(i, n) cout << lz[bkId[i]][a[i]] << ' ';

    return 0;
}