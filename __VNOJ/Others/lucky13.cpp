#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < n; i++)

long long a, b;

int const N = 17;

int digit[N];
long long dp[N][2][2];

long long Get(long long x)
{
    int n = 0;
    while (x)
    {
        digit[n++] = x % 10;
        x /= 10;
    }

    reverse(digit, digit + n);

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    REP(i, n) FOR(r, 0, 1) FOR(one, 0, 1)
    {
        int lim = r ? 9 : digit[i];
        FOR(d, 0, lim) 
        {
            if (one && d == 3) continue;
            dp[i + 1][r | (d < lim)][d == 1] += dp[i][r][one];
        }
    }

    long long res = 0;
    FOR(r, 0, 1) FOR(one, 0, 1) res += dp[n][r][one];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> a >> b) cout << Get(b) - Get(a - 1) << '\n';

    return 0;
}