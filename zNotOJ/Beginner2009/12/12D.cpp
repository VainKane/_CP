#include <bits/stdc++.h>

using namespace std;

int n;
int a[109];

long long dp[109][109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    // freopen("12D.inp", "r", stdin);
    // freopen("12D.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) dp[i][i] = a[i] * a[i - 1] * a[i + 1];

    for (int l = 1; l <= n - 2; l++)
    {
        for (int i = 2; i <= n - l; i++)
        {
            int j = i + l;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k <= j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + 1ll * a[k] * a[i - 1] * a[j + 1]);
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[2][n - 1];

    return 0;
}