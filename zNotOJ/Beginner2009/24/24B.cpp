#include <bits/stdc++.h> 

using namespace std;

int const N = 15;

int n;
int k;

long long dp[(1 << N) + 5][N + 5];
long long res = 0;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int TurnOn(int i, int mask)
{
    return mask | (1 << i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!bit(i, mask)) continue;
            for (int j = 0; j < n; j++)
            {
                if (bit(j, mask)) continue;
                if (abs(i - j) > k) continue;

                dp[TurnOn(j, mask)][j] += dp[mask][i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        res += dp[(1 << n) - 1][i];
    }

    // for (int mask = 0; mask < (1 << n); mask++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << dp[mask][i] << ' ';
    //     }

    //     cout << '\n';
    // }

    cout << res;

    return 0;
}