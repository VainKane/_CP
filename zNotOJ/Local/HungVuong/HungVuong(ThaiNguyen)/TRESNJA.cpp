#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "TRESNJA"

int const N = 20;

long long a, b;

int digits[N];
long long dp[N][2][15][N][2030];

long long Get(long long x)
{
    int n = 0;
    while (x)
    {
        digits[n++] = x % 10;
        x /= 10;
    }

    reverse(digits, digits + n);

    memset(dp, 0, sizeof dp);
    FOR(d, 0, digits[0]) dp[1][d < digits[0]][d][1][n == 1 ? d : 0] = 1;

    FOR(i, 1, n - 1) FOR(r, 0, 1) FOR(digit, 0, 9) FOR(l, 1, n) FOR(s, 0, 9 * i * i)
    {
        if (!dp[i][r][digit][l][s]) continue;
        int lim = r ? 9 : digits[i];

        FOR(d, 0, lim)
        {
            int newl = l + 1;
            int news = s;

            if (d != digit)
            {
                newl = 1;
                news += digit * l * l;

                if (i == n - 1) news += d;
            }
            else if (i == n - 1) news += d * newl * newl;

            dp[i + 1][r | (d < lim)][d][newl][news] += dp[i][r][digit][l][s];
        }
    }

    long long res = 0;
    FOR(r, 0, 1) FOR(d, 0, 9) FOR(l, 1, n) FOR(s, 0, min(9 * n * n, 2025))
        res += dp[n][r][d][l][s] * s;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> a >> b;
    cout << Get(b) - Get(a - 1);

    return 0;
}