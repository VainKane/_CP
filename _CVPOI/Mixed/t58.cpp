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
#define name ""
#define y1 sdkfjhksjdfh

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const lim = 2e5;
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

int m, n;
int x1, y1, x2, y2;

int f[N], inv[N];

void Init()
{
    f[0] = 1;
    FOR(i, 1, lim) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[lim] = PowMod(f[lim], MOD - 2);
    FORD(i, lim - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
}

int C(int k, int n)
{
    if (k > n) return 0;
    return 1LL * f[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int Cal(int x1, int y1, int x2, int y2)
{
    int a = x2 - x1, b = y2 - y1;
    return C(a, a + b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    cin >> x1 >> y1 >> x2 >> y2;

    Init();

    int res = Cal(1, 1, m, n);

    FOR(x, x1, x2) res = (res - 1LL * Cal(1, 1, x, y1 - 1) * Cal(x, y1, m, n)) % MOD;
    FOR(y, y1, y2) res = (res - 1LL * Cal(1, 1, x1 - 1, y) * Cal(x1, y, m, n)) % MOD;
    cout << (res + MOD) % MOD;

    return 0;
}