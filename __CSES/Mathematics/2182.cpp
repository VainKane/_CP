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

int n;
int k[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int cnt = 1, sum = 1;
    int cnt2 = 1;

    bool square = true;
    int x = 1, sqr = 1;

    FOR(i, 1, n)
    {
        int p, m;
        cin >> p >> m;

        if (m & 1) square = false;
        k[i] = m + 1;

        cnt = 1LL * cnt * (m + 1) % MOD;
        cnt2 = 1LL * cnt2 * (m + 1) % (MOD - 1);
        sum = 1LL * sum * (PowMod(p, m + 1) - 1) % MOD * PowMod(p - 1, MOD - 2) % MOD;
        
        x = 1LL * x * PowMod(p, m) % MOD;
        sqr = 1LL * sqr * PowMod(p, m / 2) % MOD;
    }


    int prod = x;
    bool div = false;

    FOR(i, 1, n)
    {
        if (!(k[i] & 1) && !div) k[i] >>= 1, div = true;
        prod = PowMod(prod, k[i]);
    }

    cout << cnt << ' ' << sum << ' ' << (square ? PowMod(sqr, cnt2) : prod);

    return 0;
}