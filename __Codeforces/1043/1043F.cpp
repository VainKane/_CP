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
int const MOD = 1e9 + 7;
int const oo = 3e5;

int n;

int cntDiv[N];
int f[N], inv[N];

int g[N];

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return res;
}

int C(int k, int n)
{
    if (k > n) return 0;

    int res = 1LL * inv[n - k] * inv[k] % MOD;
    return 1LL * res * f[n] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cntDiv[x]++;
    }

    f[0] = 1;
    FOR(i, 1, oo) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[oo] = PowMod(f[oo], MOD - 2);
    FORD(i, oo - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD; 

    FOR(i, 1, oo) for (int j = 2 * i; j <= oo; j += i) cntDiv[i] += cntDiv[j];

    FOR(k, 1, 7)
    {
        FORD(i, oo, 1)
        {
            g[i] = C(k, cntDiv[i]);
            for (int j = 2 * i; j <= oo; j += i) Sub(g[i], g[j]);
        }

        if (g[1])
        {
            cout << k;
            return 0;
        }
    }

    cout << -1;

    return 0;
}