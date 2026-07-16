#include <bits/stdc++.h>

using namespace std;

int const N = 29;

int n;
int a[N][N];
long long dp[(1 << 20) + 10];

int bit(int i, long long x)
{
    return (x >> i) & 1;
}

long long TurnOff(int i, long long x)
{
    return x & (~(1 << i));
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

    for (int x = 0; x < (1 << n); x++)
    {
        int k = __builtin_popcount(x);
        for (int i = 0; i < n; i++)
        {
            if (bit(i, x))
            {
                dp[x] = max(dp[x], dp[TurnOff(i, x)] + a[i][k]);
            }
        }
    }

    cout << dp[(1 << n) - 1];

    return 0;
}
