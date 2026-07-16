#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a ,b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 2009;

int dp[N][N];
string s1, s2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1;
    
    s2 = s1;
    reverse(all(s2));
    int n = s1.size();

    s1 = " " + s1;
    s2 = " " + s2;

    FOR(i, 1, n) FOR(j, 1, n)
    {
        if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

    string res = "";

    int m = n;
    while (m && n)
    {
        if (s1[n] == s2[m]) 
        {
            res += s1[n];
            n--; m--;
        }
        else 
        {
            if (dp[n - 1][m] > dp[n][m - 1]) n--;
            else m--;
        }
    }

    cout << res;

    return 0;
}