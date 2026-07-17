#include <bits/stdc++.h>

using namespace std;

int n;
string s1;
string s2= "";

int res = 0;

int dp[5009][5009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s1;

    for (auto chr : s1) s2 = chr + s2;
    s1 = " " + s1;
    s2 = " " + s2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << n - dp[n][n];

    return 0;
}