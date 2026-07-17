#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 5;
int const H = 109;
int const MOD = 1e9 + 7;

int n, h;
int a[N];

int dp[N][H];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (!a[1]) for (int x = 1; x <= h; x++) dp[1][x] = 1;
    else dp[1][a[1]] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (a[i])
        {
            dp[i][a[i]] = (1ll * dp[i - 1][a[i]] + dp[i - 1][a[i] + 1] + dp[i - 1][a[i] - 1]) % MOD;
        }
        else
        {
            for (int x = 1; x <= h; x++)
            {
                dp[i][x] = (1ll * dp[i - 1][x] + dp[i - 1][x + 1] + dp[i - 1][x - 1]) % MOD;
            }
        }
    }

    int res = 0;
    for (int x = 1; x <= h; x++)
    {
        res += dp[n][x];
        res %= MOD;
    } 

    cout << res;

    return 0;
}