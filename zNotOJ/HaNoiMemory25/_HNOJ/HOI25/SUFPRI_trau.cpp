#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "SUFPRI"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const MOD = 1e9 + 7;

long long l, r;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

bool Prime(long long x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1;
}

bool Check(long long x, long long suf)
{
    while (suf)
    {
        if (x % 10 != suf % 10) return false;
        x /= 10; suf /= 10;
    }

    return true;
}

int Cal(long long a, long long b)
{
    long long x = b;
    while (true)
    {
        if (Check(x, a)) return x % MOD;
        x += b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> l >> r;
    
    vector<long long> v;
    for (long long i = l; i <= r; i++) if (Prime(i)) v.push_back(i);

    int res = 0;
    REP(i, sz(v) - 1) Add(res, Cal(v[i], v[i + 1]));
    cout << res;

    return 0;
}