#include <bits/stdc++.h>

using namespace std;

int const MOD = 666013;

int n;
int h;
int k;

int dp[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> h >> k;

    dp[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int u = 0; u <= h; u++)
        {
            for (int v = 0; v <= h; v++)
            {
               if (abs(u - v) > k) continue;

                dp[i][u] = (dp[i][u] + dp[i - 1][v]) % MOD;
            }
        }
    }

    cout << dp[n][h];

    return 0;
}