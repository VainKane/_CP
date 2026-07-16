#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e4 + 10];
int dp[(int)1e4 + 10];

int res = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }

    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << res;
    return 0;
}