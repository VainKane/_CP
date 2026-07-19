#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 3005;

int n;
double p[N];

double dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> p[i];

    dp[0][0] = 1;
    FOR(i, 1, n) FOR(j, 0, i)
    {
        dp[i][j] = dp[i - 1][j] * (1 - p[i]);
        if (j) dp[i][j] += dp[i - 1][j - 1] * p[i];
    }

    double res = 0;
    FOR(j, n / 2 + 1, n) res += dp[n][j];

    cout << fixed << setprecision(10) << res;

    return 0;
}