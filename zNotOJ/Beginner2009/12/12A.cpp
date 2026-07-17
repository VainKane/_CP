#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[109][109];
int dp[109][109];

int res = INT_MAX;
deque<int> mark;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    memset(dp, 0x3f, sizeof dp);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        dp[i][1] = a[i][1];
    }


    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];
        }
    }      

    int k;
    for (int i = 0; i <= m + 1; i++)
    {
        if (res > dp[i][n])
        {
            res = dp[i][n];
            k = i;
        }
    }

    for (int j = n; j >= 1; j--)
    {
        mark.push_front(k);
        int mi = min({dp[k - 1][j - 1], dp[k][j - 1], dp[k + 1][j - 1]});
        
        if (mi == dp[k - 1][j - 1]) k -= 1;
        else if (mi == dp[k + 1][j - 1]) k += 1;
    }

    cout << res << '\n';
    for (auto val : mark) cout << val << ' ';

    return 0;
}