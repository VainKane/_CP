#include <bits/stdc++.h>

using namespace std;

int const mod = 1000000007;

int n;
int p;

int a[109];
int dp[109][10009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            if (j == a[i] && i == 1)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = dp[i - 1][j];

            if (j >= a[i])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
                dp[i][j] %= mod;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= p; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }

    cout << dp[n][p];

    return 0;
}