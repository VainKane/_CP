#include <bits/stdc++.h>

using namespace std;

int const N = 29;

int n;
int a[N][N];
long long dp[(1 << 20) + 10];

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int on(int i, int mask)
{
    return mask | (1 << i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int k = __builtin_popcount(mask);
        for (int i = 0; i < n; i++)
        {
            if (bit(i, mask)) continue;
            dp[on(i, mask)] = max(dp[on(i, mask)], dp[mask] + a[i][k + 1]);
        }
    }

    cout << dp[(1 << n) - 1];

    return 0;
}