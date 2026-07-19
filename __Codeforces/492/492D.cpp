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

long long const oo = 1e18;
int n, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x >> y;
    while (n--)
    {
        int a; cin >> a;

        long long l = 1;
        long long r = max(x, y) * 1e9;
        long long t = r;

        while (l <= r)
        {
            long long mid = (l + r) >> 1;
            if (mid / x + mid / y >= a)
            {
                t = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        long long t1 = t / y * y;
        long long t2 = t / x * x;

        if (t1 > t2) cout << "Vanya\n";
        else if (t1 < t2) cout << "Vova\n";
        else cout << "Both\n";
    }

    return 0;
}