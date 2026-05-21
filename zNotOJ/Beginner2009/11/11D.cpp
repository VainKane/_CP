#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int w[109];
int v[109];
int dp[109][(int)1e4 + 10];

deque<int> mark;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) 
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    int k = m;
    for (int i = n; i >= 1; i--)
    {
        if (k <= 0) break;

        if (k >= w[i])
        {
            if (dp[i - 1][k] < dp[i - 1][k - w[i]] + v[i])
            {
                mark.push_front(i);
                k -= w[i];
            }
        }
        
    }

    cout << dp[n][m] << '\n';
    cout << mark.size() << '\n';
    for (auto val : mark) cout << val << ' ';

    return 0;
}