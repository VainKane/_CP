#include <bits/stdc++.h>

using namespace std;

#define name "MICOST"

int const N = 1e4 + 5;

int n;
int c;
int a[N];

long long dp[N][209];
long long res = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 200; j++)
        {
            dp[i][j] = 1e18;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= a[i] + 100; j++)
        {
            for (int k = a[i - 1]; k <= a[i - 1] + 100; k++)
            {
                int d = 1ll * (j - a[i]) * (j - a[i]);
                int delta = 1ll * c * abs(j - k);
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + delta + d);
            }
        }
    }

    for (int h = a[n]; h <= a[n] + 100; h++)
    {
        res = min(res, dp[n][h]);
    }

    cout << res;

    return 0;
}