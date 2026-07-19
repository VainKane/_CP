#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second

int const N = 1e5 + 5;
int const LOG = 7;

int n;
int x;
int y;

int a[N];
int s[N][10];

long long dp[N][(1 << LOG) + 5];

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int on(int i , int mask)
{
    return mask | (1 << i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x >> y;
    
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> s[i][j];
        }
    }

    sort(a + 1, a + n + 1);

    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << x); mask++)
        {
            dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
            for (int j = 0; j < x; j++)
            {
                if (bit(j, mask)) continue;
                dp[i + 1][on(j, mask)] = max(dp[i + 1][on(j, mask)], dp[i][mask] + s[i + 1][j]);
            }
        }
    }

    return 0;
}