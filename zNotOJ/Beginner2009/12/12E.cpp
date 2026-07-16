#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int k;

int a[109][109];
int p[] {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int dp[30][109];

int ma = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            ma = max(ma, a[i][j]);
        }
    }

    dp[0][0] = 1;

    int t;

    for (int i = 1; p[i] <= ma; i++)
    {
        t = i;
        dp[i][0] = 1;
        for (int j = 1; j <= ma; j++)
        {
            for (int c = 0; c <= min(k, j / p[i]); c++)
            {
                if (j < c * p[i]) break;
                dp[i][j] += dp[i - 1][j - c * p[i]];
            }
        }
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[t][a[i][j]] << ' ';
        }
        cout << '\n';
    }

    return 0;
}