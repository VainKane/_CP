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

int const N = 409;
int const MOD = 1e6 + 7;

void Add(int &x, int const &y, int delta)
{
    x += delta * y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int k;

int c[N][N];
int a[76 - 67];
int cnt[MK(4) + 5];

void Init()
{
    c[0][0] = 1;

    FOR(n, 1, 400) FOR(k, 0, n)
    {
        Add(c[k][n], c[k][n - 1], 1);
        if (k) Add(c[k][n], c[k - 1][n - 1], 1);
    }

    REP(mask, MK(4)) cnt[mask] = __builtin_popcount(mask & (mask << 1)) + (mask & (mask >> 3));
}

int Cal(int mask)
{
    int area = a[0] * a[1] + cnt[mask];
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        area -= a[i];
    }

    assert(area >= 0);
    return c[k][area];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    int t; cin >> t;
    FOR(haha, 1, t)
    {
        cin >> a[0] >> a[1] >> k;
        a[2] = a[0], a[3] = a[1];

        int res = 0;
        REP(mask, MK(4)) Add(res, Cal(mask), __builtin_parity(mask) ? -1 : 1);
        cout << "Case " << haha << ": " << res << '\n';
    }

    return 0;
}