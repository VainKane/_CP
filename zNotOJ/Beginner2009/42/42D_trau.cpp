#include <bits/stdc++.h>

using namespace std;

int const N = 709;
int const MOD = 30103;

int n;

int a[N];
int dp[N][N];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 1;
        }
    }

    for (int u = 1; u <= n; u++)
    {
        for (int v = n; v > u; v--)
        {
            for (int p = 1; p < u; p++)
            {
                for (int q = n; q > v; q--)
                {
                    if (a[u] + a[v] >= a[p] + a[q]) continue;
                    dp[u][v] = (dp[u][v] + dp[p][q]) % MOD;
                }
            }
            res = (res + dp[u][v] - 1 + MOD) % MOD;
        }
    }

    cout << res;

    return 0;
}