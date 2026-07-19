#include <bits/stdc++.h>

using namespace std;

#define name "29B"

int const N = 1e4 + 5;
int const MOD = 1e9;

int n;
int k;

int a[N];

int dp[19][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            for (int p = j + 1; p <= n; p++)
            {
                if (a[j] <= a[p]) continue;

                dp[i][j] += dp[i - 1][p];
                dp[i][j] %= MOD;
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        // cout << i << ' ' << dp[k][i] << '\n';
        res += dp[k][i];
        res %= MOD;
    }

    cout << res;

    return 0;
}