#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 3009;

string s, t;
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> t;
    
    int n = s.size();
    int m = t.size();
    
    s = " " + s;
    t = " " + t;

    FOR(i, 1, n) FOR(j, 1, m) 
    {
        if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

    string res = "";
    while (n && m)
    {
        if (s[n] == t[m]) 
        {
            res += s[n];
            m--;
            n--;
        }
        else if (dp[n][m - 1] > dp[n - 1][m]) m--;
        else n--;
    }

    reverse(all(res));
    cout << res;

    return 0;
}