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

int const N = 22;

int n;
int a[N];

bool Check(long long x)
{
    long long k = sqrt(x);
    return k * k == x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> a[i];

    int res = 0;

    REP(mask, MK(n))
    {
        long long p = 1;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            p *= a[i];
        }

        res += Check(p);

        // if (Check(p))
        // {
        //     cout << p << '\n';
        //     REP(i, n) if (BIT(i, mask)) cout << i + 1 << ' ';
        //     cout << '\n';
        // }
    }

    cout << res - 1;

    return 0;
}