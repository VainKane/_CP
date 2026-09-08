#include <bits/stdc++.h>

using namespace std;

int const N = 2009;

string s1, s2;
int n, m;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    s1 = " " + s1;
    s2 = " " + s2;

    n = s1.size() - 1;
    m = s2.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
        
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = j;

            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
            else 
            {
                int x = dp[i - 1][j] + 1; // xoa
                int y = dp[i][j - 1] + 1; // them
                int z = dp[i - 1][j - 1] + 1; // sua
                
                dp[i][j] = min({x, y, z});
            }
        }
    }

    cout << dp[n][m];

    return 0;
}