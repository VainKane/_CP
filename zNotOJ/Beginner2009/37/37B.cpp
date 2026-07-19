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

int n;
long long k;

int a[N];

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

long long Cal(int mask)
{
    long long lcm = 1;

    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        if ((double)a[i] / GCD(lcm, a[i]) > (double)k / lcm) return 0;
        lcm = LCM(lcm, a[i]);
    }

    return k / lcm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    REP(i, n) cin >> a[i];

    long long res1 = 0, res2 = 0;

    FOR(mask, 1, MK(n) - 1)
    {
        int cnt = __builtin_popcount(mask);
        int delta = (cnt & 1) ? 1 : -1;

        res1 += delta * Cal(mask);
        res2 += delta * cnt * Cal(mask);
    }

    cout << res1 << ' ' << res2;

    return 0;
}