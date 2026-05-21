#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int const MOD = 1e9 + 7;

int n;
int a[N];

int dp[N];
int f[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        dp[i] = f[i] = 1;
    }

    int idx;
    int ma = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (dp[i] < dp[j] + 1) f[i] = f[j];
                else if (dp[i] == dp[j] + 1) 
                {
                    f[i] += f[j];
                    f[i] %= MOD;
                }

                dp[i] = max(dp[i], dp[j] + 1);
            }

            ma = max(ma, dp[i]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == ma) res += f[i];
        res %= MOD;
        // cout << f[i] << ' ';
    }

    cout << res;

    return 0;
}
