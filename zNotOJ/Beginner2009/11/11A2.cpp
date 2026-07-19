#include <bits/stdc++.h>

using namespace std;

int n;
int a[309];

bool dp[309][91000];
int s1 = 0;
int s2 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < 0) s1 += a[i];
        else s2 += a[i];

    }

    int d = abs(s1);
    dp[0][d] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = s2; j >= s1; j--)
        {
            if (dp[i - 1][j + d])
            {
                dp[i][j + d] = 1;     
                dp[i][j + a[i] + d] = 1;  
            }
        }
    }

    for (int j = s1; j <= s2; j++)
    {
        if (dp[n][j + d]) cout << j << ' ';
    }

    return 0;
}
