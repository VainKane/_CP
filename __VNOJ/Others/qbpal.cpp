#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 123;

int n;
string s;

unsigned long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    n = s.size();
    s = " " + s;

    FOR(i, 1, n) dp[i][i] = 1;
    FORD(i, n, 1) FOR(j, i + 1, n)
    {
        dp[i][j] = dp[i + 1][j] - dp[i + 1][j - 1] + dp[i][j - 1];
        if (s[i] == s[j]) dp[i][j] += dp[i + 1][j - 1] + 1;
    }

    cout << dp[1][n];

    return 0;
}