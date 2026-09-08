#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[109][109];
int dp[109][109];

int res = 0;
deque<int> mark;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    memset(dp, -0x3f, sizeof dp);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        dp[i][1] = a[i][1];
    }

    dp[0][1] = dp[m][1];
    dp[m + 1][1] = dp[1][1];

    for (int j = 2; j <= n; j++)
    {
        dp[0][j - 1] = dp[m][j - 1];
        dp[m + 1][j - 1] = dp[1][j - 1];
        for (int i = 1; i <= m; i++)
        {
            dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1], }) + a[i][j];
        }
    }      

    int k;
    for (int i = 1; i <= m; i++)
    {
        if (res < dp[i][n])
        {
            res = dp[i][n];
            k = i;
        }
    }

    for (int j = n; j >= 1; j--)
    {
        mark.push_front(k);
        int ma = max({dp[k - 1][j - 1], dp[k][j - 1], dp[k + 1][j - 1]});
        
        if (ma == dp[k - 1][j - 1])
        {
            k -= 1;
            if (k == 0) k = m;
        }
        else if (ma == dp[k + 1][j - 1]) 
        {
            k += 1;
            if (k == m + 1) k = 1;
        }
    }

    // cout << '\n';
    // for (int i = 0; i <= m + 1; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    cout << res << '\n';
    for (auto val : mark) cout << val << ' ';

    return 0;
}