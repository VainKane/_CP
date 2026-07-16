#include <bits/stdc++.h>

using namespace std;

int const MOD = 2021;
int const N = 1e5 + 5;

long long n;
int k;

int dp[N][29];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (2 * j * dp[i - 1][j] + max(0, i - 2 * (j - 1)) * dp[i - 1][j - 1]) % MOD;
        }
    }

    cout << dp[n][k];

    return 0;
}