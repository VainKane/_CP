#include <bits/stdc++.h>

using namespace std;

#define name "TRIANGLE"

int const N = 2009;

int n;
int m;
int k;

int a[N][N];
long long p[N][N];
long long t[N][N];
long long dp[N][N];

long long res = -1e18;

long long GetSumP(int i, int j, int u, int v)
{
    return p[u][v] - p[u][j - 1] - p[i - 1][v] + p[i - 1][j - 1];
}

long long GetSumT(int i, int j, int u, int v)
{
    return t[u][v] - t[i - 1][j - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        p[i][1] = p[i - 1][1] + a[i][1];
        t[i][1] = a[i][1];
    }
    for (int j = 1; j <= n; j++)
    {
        p[1][j] = p[1][j - 1] + a[1][j];
        t[1][j] = a[1][j];
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            t[i][j] = t[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        dp[1][1] += GetSumP(i, 1, i, i);
    }

    for (int i = 2; i <= m - k + 1; i++)
    {
        dp[i][1] = dp[i - 1][1] - GetSumT(i - 1, 1, i + k - 2, k) + GetSumP(i + k - 1, 1, i + k - 1, k);
    }

    for (int i = 1; i <= m - k + 1; i++)
    {
        res = max(res, dp[i][1]);
        for (int j = 2; j <= n - k + 1; j++)
        {
            dp[i][j] = dp[i][j - 1] - GetSumP(i, j - 1, i + k - 1, j - 1) + GetSumT(i, j, i + k - 1, j + k - 1);
            // int x = GetSumP(i, j - 1, i + k - 1, j - 1);
            // int y = GetSumT(i, j, i + k - 1, j + k - 1);
            res = max(res, dp[i][j]);
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }

    cout << res;

    return 0;
}