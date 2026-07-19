#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e6 + 5;

int n;
string s;

int dp[N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    
    n = s.size();
    s = " " + s;

    FOR(i, 1, n)
    {
        int k = s[i] == 'A';
        dp[i][0] = min(dp[i - 1][0] + !k, dp[i - 1][1] + k + 1);
        dp[i][1] = min(dp[i - 1][1] + k, dp[i - 1][0] + !k + 1);
    }
    
    cout << dp[n][0];

    return 0;
}