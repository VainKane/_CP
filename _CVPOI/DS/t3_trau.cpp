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

int const N = 1e5 + 5;
long long const oo = 1e18;

int n;
int h[N], a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i];

    long long res = oo;

    FOR(i, 1, n)
    {
        FOR(j, 1, i) a[j] = h[j] + i - j;
        FOR(j, i + 1, n) a[j] = h[j] + j - i;

        sort(a + 1, a + n + 1);
        int med = max({i, n - i + 1, a[(n + 1) / 2]});

        long long cost = 0;
        FOR(j, 1, n) cost += abs(h[j] + abs(i - j) - med);
        mini(res, cost);
    }

    cout << res;

    return 0;
}