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

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1.2e7 + 1;

int n, q;
int a[5009];

bitset<N> dp;
int s = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], s += a[i];

    dp[0] = 1;
    FOR(i, 1, n) dp |= (dp << a[i]);

    while (q--)
    {
        int x; cin >> x;
        cout << ((x > s || !dp[x]) ? "no\n" : "yes\n");
    }

    return 0;
}