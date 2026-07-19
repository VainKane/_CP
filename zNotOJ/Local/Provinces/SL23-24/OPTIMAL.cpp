#include <bits/stdc++.h>

using namespace std;

int const N = 1009;
int const MOD = 1e9 + 7;

int x, y;
int t;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> t;

    if (t == 1) cout << abs(x) + abs(y);
    else
    {
        x = abs(x) + 1;
        y = abs(y) + 1;

        dp[1][1] = 1;

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (i * j == 1) continue;
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
            }
        }

        cout << dp[x][y];
    }

    return 0;
}