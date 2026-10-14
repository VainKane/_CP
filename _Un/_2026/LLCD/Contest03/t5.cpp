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

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;
int const lim = 1e6;
int const MOD = 998244353;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

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
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

int const inv2 = PowMod(2, MOD - 2);

int sum[N], sqSum[N];
int f[N], inv[N];

void Init()
{
    inv[1] = 1;
    FOR(i, 2, lim) inv[i] = MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        Add(sum[x], x);
        sqSum[x] = (sqSum[x] + 1LL * x * x) % MOD;
    }

    FOR(i, 1, lim) for (int j = 2 * i; j <= lim; j += i)
    {
        Add(sum[i], sum[j]);
        Add(sqSum[i], sqSum[j]);
    }
   
    int res = 0;
    FORD(i, lim, 1)
    {
        f[i] = (1LL * sum[i] * sum[i] - sqSum[i]) % MOD;
        if (f[i] < 0) f[i] += MOD;
        f[i] = 1LL * f[i] * inv[2] % MOD;

        for (int j = 2 * i; j <= lim; j += i) Sub(f[i], f[j]);
        res = (res + 1LL * f[i] * inv[i]) % MOD;
    }

    cout << res;

    return 0;
}