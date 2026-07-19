#include <bits/stdc++.h>

using namespace std;

int const mod = 1000000007;

string s;
string s1;
string s2;

int dp[109][109][3];

int n;
int m;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> s1 >> s2;

    s = " " + s;
    s1 = " " + s1;
    s2 = " " + s2;

    n = s.size() - 1;
    m = s1.size() - 1;

    for (int j = 1; j <= m; j++)
    {
        
        if (s1[j] == s[1]) 
        {
            dp[1][j][1] = 1; 
        }
        if (s2[j] == s[1])
        {
            dp[1][j][2] = 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[j] == s[i])
            {
                for (int k = 1; k < j; k++)
                {
                    dp[i][j][1] += dp[i - 1][k][2];
                    dp[i][j][1] %= mod;
                }
            }
            if (s2[j] == s[i])
            {
                for (int k = 1; k < j; k++)
                {
                    dp[i][j][2] += dp[i - 1][k][1];
                    dp[i][j][2] %= mod;
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j][1] << ' ' << dp[i][j][2] << " | ";
    //     }
    //     cout << '\n';
    // }


    for (int j = 1; j <= m; j++)
    {
        res += dp[n][j][1];
        res %= mod;
        res += dp[n][j][2];
        res %= mod;
    }

    cout << res;

    return 0;
}