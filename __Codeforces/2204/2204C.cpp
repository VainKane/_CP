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

int a, b, c;
long long m;

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
    return (1LL * a * b) / GCD(a, b);
}

long long Cal(int a, int b, int c)
{
    long long cntabc = m / LCM(LCM(a, b), c);
    long long cntab = m / LCM(a, b);
    long long cntac = m / LCM(a, c);
    long long cnta = m / a - cntab - cntac + cntabc;

    long long res = cnta * 6;
    res += (cntab - cntabc) * 3;
    res += (cntac - cntabc) * 3;
    res += cntabc * 2;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> m;
        cout << Cal(a, b, c) << ' ' << Cal(b, a, c) << ' ' << Cal(c, b, a) << '\n';
    }

    return 0;
}