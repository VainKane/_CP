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

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

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

int q, n, m;
int f[N];

int C(int n, int k)
{
    return 1LL * f[n] * PowMod(f[n - k], MOD - 2) % MOD * PowMod(f[k], MOD - 2) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> q >> n >> m;

    f[0] = 1;
    FOR(i, 1, m) f[i] = 1LL * f[i - 1] * i % MOD;

    int k = 0;
    FOR(i, 1, n - 1) k += GCD(i, q) == 1;

    cout << k + 1 << '\n';
    if (k > m) cout << "NU";
    else cout << C(m - 1, k - 1);

    return 0;
}