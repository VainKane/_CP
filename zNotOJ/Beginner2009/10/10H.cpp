#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int a[109];
int pre[109];

long double dp[109][109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("10H.inp", "r", stdin);
    // freopen("10H.out", "w", stdout);

    cout << fixed << setprecision(5);

    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        long double avg = (long double)pre[i] / i;
        for (int p = 1; p <= i; p++)
        {
            dp[i][1] += (a[p] - avg) * (a[p] - avg);
        }
        dp[i][1] /= i;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(k, i); j++)
        {
            dp[i][j] = LLONG_MAX;
            
            for (int p = 1; p <= i - 1; p++)
            {
                long double avg = pre[i] - pre[p];
                avg /= i - p;

                long double var = 0; 

                for (int q = p + 1; q <= i; q++)
                {
                    var += (a[q] - avg) * (a[q] - avg);
                }

                var /= i - p;

                dp[i][j] = min(dp[i][j], dp[p][j - 1] + var);
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }

    cout << dp[n][k];

    return 0;
}