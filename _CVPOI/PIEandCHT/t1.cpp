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

int const N = 36;

long long GCD(long long a, long long b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}

int n;
long long t;

int a[N], c[N];
int f[367];

void Init()
{
    REP(i, n) for (f[c[i] = 1] = a[i] > 1; f[c[i]]; c[i]++)
        f[c[i] + 1] = (f[c[i]] + f[c[i] - 1]) % a[i];
}

long long Cal(int mask)
{
    long long lcm = 1;
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        if ((double)lcm / t > (double)GCD(lcm, c[i]) / c[i]) return 0;
        lcm = LCM(lcm, c[i]);
    }

    return t / lcm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    REP(i, n) cin >> a[i];

    Init();

    long long res = 0;
    FOR(mask, 1, MK(n) - 1) res += (__builtin_parity(mask) ? 1 : -1) * Cal(mask);
    cout << res;

    return 0;
}