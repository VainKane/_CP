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

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y, int delta)
{
    x += delta * y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int n;
int f[MK(20) + 5];
int pw[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        f[x]++;
    }

    REP(i, 20) FOR(x, 0, 1e6) if (!BIT(i, x)) f[x] += f[x | MK(i)];

    pw[0] = 1;
    FOR(i, 1, n) pw[i] = 2 * pw[i - 1] % MOD;

    int res = 0;
    FOR(mask, 0, 1e6) Add(res, pw[f[mask]] - 1, __builtin_parity(mask) ? -1 : 1);
    cout << res;

    return 0;
}