#include <bits/stdc++.h>

using namespace std;

#define name "MICOST"

int const N = 1e4 + 5;
int const H = 2009;

int n;
int c;

int a[N];

long long dp[N][H];
long long f[N][H];
long long g[N][H];

long long res = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 2000; j++)
        {
            f[i][j] = g[i][j] = 1e18;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= a[i] + 1000; j++)
        {
            int delta = (j - a[i]) * (j - a[i]);
            int d = c * j;

            dp[i][j] = min(f[i - 1][j] + d, g[i - 1][j] - d) + delta;
            dp[1][j] = delta;
        }

        for (int k = a[i]; k <= a[i] + 1000; k++)
        {
            f[i][k] = min(f[i][k - 1], dp[i][k] - c * k);
        }
        for (int k = a[i] + 1000; k >= a[i]; k--)
        {
            g[i][k] = min(g[i][k - 1], dp[i][k] +  c * k);
        }
    }

    cout << dp[4][1];

    return 0;
}