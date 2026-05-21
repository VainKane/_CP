#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "STRING"

int const N = 1e3 + 5;

int n, m;
string s, t;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s >> t;

    n = s.size();
    m = t.size();
    s = " " + s;
    t = " " + t;

    FOR(i, 1, n) dp[i][0] = i;
    FOR(j, 1, m) dp[0][j] = j;

    FOR(i, 1, n) FOR(j, 1, m)
    {
        if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    }

    cout << dp[n][m];

    return 0;
}