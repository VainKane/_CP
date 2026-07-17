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

int m, n;
long long k;

long long Cal(long long x)
{
    long long res = 0;
    FOR(i, 1, m) res += min(x / i, 1LL * n);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    long long l = 1;
    long long r = 1LL * m * n;
    long long res = r;

    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (Cal(mid) >= k)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}