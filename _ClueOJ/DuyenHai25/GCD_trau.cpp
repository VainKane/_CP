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

int const N = 1009;

int n;
long long a[N];

namespace Sub2
{
    bool CheckSub()
    {
        return n <= 20;
    }

    long long GCD(long long a, long long b)
    {
        while (true)
        {
            if (a == 0 || b == 0 || a == b) return a | b;
            if (a > b) a %= b; else b %= a;
        }
    }

    void Process()
    {
        int res = 0;

        REP(mask, MK(n))
        {
            long long gcd = 0;
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp);
                gcd = GCD(gcd, a[i + 1]);
            }

            if (gcd > 1) maxi(res, __builtin_popcount(mask));
        }

        cout << res;
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        FOR(i, 1, n) if (a[i] > 1e6) return false;
        return true;
    }

    int cntDiv[(int)1e6 + 5];

    void Process()
    {
        FOR(i, 1, n) cntDiv[a[i]]++;
        FOR(i, 1, 1e6) for (int j = 2 * i; j <= 1e6; j += i) cntDiv[i] += cntDiv[j];
        cout << *max_element(cntDiv + 2, cntDiv + (int)1e6 + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}