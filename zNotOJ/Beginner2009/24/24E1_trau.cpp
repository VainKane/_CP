#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

int n;
int dp[(1 << 5) + 5][N];

int flip(int i, int mask)
{
    return mask ^ (1 << i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    // 0 -> chan
    // 1 -> le

    dp[0][1] = 5;
    for (int i = 1; i < 5; i++) dp[1 << i][1] = 1;

    // for (int i = 1; i < n; i++)
    // {
    //     for (int mask = 0; mask < (1 << 5); mask++)
    //     {
    //         dp[mask][i + 1] = (dp[mask][i + 1] + 5ll * dp[mask][i]) % MOD;
    //         for (int j = 0; j < 5; j++)
    //         {
    //             dp[flip(j, mask)][i + 1] = (dp[flip(j, mask)][i + 1] + dp[mask][i]) % MOD;
    //         }
    //     }
    // }

    for (int i = 2; i <= n; i++)
    {
        for (int mask = 0; mask < (1 << 5); mask++)
        {
            dp[mask][i] = (dp[mask][i] + 5ll * dp[mask][i - 1]) % MOD;

            for (int j = 0; j < 5; j++)
            {
                dp[mask][i] = (dp[mask][i] + dp[flip(j, mask)][i - 1]) % MOD;
            }
        }
    }

    cout << dp[0][n];

    return 0;
}