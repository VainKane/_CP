#include <bits/stdc++.h>

using namespace std;

int const N = 15;

int n;
int a[N + 5];
int dp[(1 << 15)][N + 5];
int cnt[(1 << 15)][N + 5];

int bit(int i, long long mask)
{
    return (mask >> i) & 1;
}

long long TurnOff(int i, long long mask)
{
    return mask & (~(1 << i));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        if (!n) exit(0);
        memset(dp, 0, sizeof dp);
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            dp[1 << i][i] = a[i];
            cnt[1 << i][i] = 1;
        }

        for (int mask = 0; mask < (1 << n); mask++)
        {
            for (int i = 0; i < n; i++)
            {
                if (!bit(i, mask)) continue;

                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    if (!bit(j, mask)) continue;

                    if (dp[mask][i] < dp[TurnOff(i, mask)][j] + abs(a[i] - a[j]))
                    {
                        dp[mask][i] = dp[TurnOff(i, mask)][j] + abs(a[i] - a[j]);
                        cnt[mask][i] = cnt[TurnOff(i, mask)][j];
                    }
                    else if (dp[mask][i] == dp[TurnOff(i, mask)][j] + abs(a[i] - a[j]))
                    {
                        cnt[mask][i] += cnt[TurnOff(i, mask)][j];
                    }
                }
            }
        }

        int res = 0;
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            int x = dp[(1 << n) - 1][i] + a[i] + 2 * n;
            if (x > res) 
            {
                c = cnt[(1 << n) - 1][i];
                res = x;
            }
            else if (x == res) c += cnt[(1 << n) - 1][i];
        }

        cout << res << ' ' << c << '\n';
    }

    return 0;
}