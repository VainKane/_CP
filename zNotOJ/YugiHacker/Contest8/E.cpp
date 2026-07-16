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
#define name "kdigit"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 21;

long long a, b;
int d, k;

long long dp[N][2][N];

long long Get(long long x)
{
    vector<int> digits;

    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }

    reverse(all(digits));
    int n = sz(digits);

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    REP(i, n) REP(r, 2) FOR(cnt, 0, k) if (dp[i][r][cnt])
    {
        int lim = r ? 9 : digits[i];
        FOR(digit, 0, lim) dp[i + 1][r | (digit < lim)][cnt + (digit == d)] += dp[i][r][cnt];
    }

    long long res = 0;
    REP(r, 2) res += dp[n][r][k];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> a >> b >> d >> k;
    cout << Get(b) - Get(a - 1);

    return 0;
}