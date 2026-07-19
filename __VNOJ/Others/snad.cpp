#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < n; i++)

int const N = 23;

int t;
unsigned long long x, y;

int digit[N];
long long dp[N][2][188];

long long Get(long long val, int s)
{
    int n = 0;
    while (val)
    {
        digit[n++] = val % 10;
        val /= 10;
    }

    reverse(digit, digit + n);

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    REP(i, n) FOR(r, 0, 1) FOR(sum, 0, s)
    {
        int lim = r ? 9 : digit[i];
        FOR(d, 0, lim) dp[i + 1][r | (d < lim)][sum + d] += dp[i][r][sum];
    }

    return dp[n][1][s] + dp[n][0][s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        long long res = 0;
        FOR(s, 1, 171) res += Get(y / s, s) - Get((x - 1) / s, s);
        cout << res << '\n';
    }

    return 0;
}