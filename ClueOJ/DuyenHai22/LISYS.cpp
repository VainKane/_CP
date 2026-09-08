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

int const N = 2e6 + 5;
int const MOD = 1e9 + 7;

int n;

int cnt = 0, s = 0;

int f[N];
int inv[N];

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

int Ck(int k, int n)
{
    if (k > n) return 0;
    int res = 1LL * f[n] * inv[n - k] % MOD;
    return 1LL * res * inv[k] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        if (x == -1) cnt++;
        else s += x;
    }

    f[0] = 1;
    FOR(i, 1, (n - 1) << 1) f[i] = 1LL * f[i - 1] * i % MOD;
    
    inv[(n - 1) << 1] = PowMod(f[(n - 1) << 1], MOD - 2);
    FORD(i, 2 * (n - 1) - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;

    int res = Ck(cnt - 1, 2 * (n - 1) - s - 1) - Ck(cnt - 1, n - s - 2);
    if (res < 0) res += MOD;
    cout << (cnt ? res : 1);

    return 0;
}