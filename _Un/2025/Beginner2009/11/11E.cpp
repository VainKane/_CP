#include <bits/stdc++.h>

using namespace std;

int n;
int a[40];

int dp[40][649][649];

int s = 0;
int res = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];

        dp[i][0][0] = 1;
    }

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            for (int k = 0; k <= s; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];

                if (j >= a[i])
                {
                    dp[i][j][k] |= dp[i - 1][j - a[i]][k];
                }
                if (k >= a[i])
                {
                    dp[i][j][k] |= dp[i - 1][j][k - a[i]];
                }
            }
        }
    }

    for (int j = 0; j <= s; j++)
    {
        for (int k = 0; k <= s; k++)
        {
            if (dp[n][j][k] && j + k <= s)
            {
                res = min(res, max({j, k, s - j - k}) - min({j, k, s - j - k}));
            }
        }
    }

    cout << res;

    return 0;
}