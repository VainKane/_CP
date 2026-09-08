#include <bits/stdc++.h>

using namespace std;

int n;

int matrix[(int)1e3 + 10][(int)1e3 + 10];

long long dp[(int)1e3 + 10][(int)1e3 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];

            if (i == 0)
            {
                if (j >= 1)
                {
                    dp[i][j] = dp[i][j - 1] + matrix[i][j];
                }
                else
                {
                    dp[i][j] = matrix[i][j];
                }
            }
            if (j == 0)
            {
                if (i >= 1)
                {
                    dp[i][j] = dp[i - 1][j] + matrix[i][j];
                }
                else
                {
                    dp[i][j] = matrix[i][j];
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }

//    cout << '\n';
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cout << dp[i][j] << ' ';
//        }
//
//        cout << '\n';
//    }

    cout << dp[n - 1][n - 1];

    return 0;
}
