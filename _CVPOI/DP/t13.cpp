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

int const N = 109;
int const M = 1e6 + 5;

int n, s = 0;
int a[N];
bitset<M> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], s += a[i];

    dp[0] = 1;
    FOR(i, 1, n) dp |= (dp << a[i]);

    long long res = 0;
    int cnt = 0;

    FORD(x, s, 0)
    {
        if (dp[x]) res += s - x + 1, cnt++;
        else res += cnt;
    }

    cout << res;

    return 0;
}