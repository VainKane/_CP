#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const N = 5e5 + 5;
int const M = 5;

int n;
int dp[(1 << M) + 5][N];

int flip(int i, int mask)
{
    return mask ^ (1 << i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    dp[0][1] = 5;
    for (int i = 0; i < 5; i++) dp[1 << i][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int mask = 0; mask < (1 << M); mask++)
        {
            dp[mask][i] = (dp[mask][i] + 5ll * dp[mask][i - 1]) % MOD;
            for (int j = 0; j < M; j++)
            {
                dp[mask][i] = (dp[mask][i] + dp[flip(j, mask)][i - 1]) % MOD;
            }
        }
    }

    for (int i = 0; i <= M; i++)
    {
        cout << dp[(1 << i) - 1][n] << ' ';
    }

    return 0;
}