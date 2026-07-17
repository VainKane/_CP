#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 3009;

int n;

int a[N];
long long dp[N][N];

long long s = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], s += a[i];

    FORD(i, n, 1) FOR(j, i, n)
    {
        if (((j - i) & 1) == (n & 1)) dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
        else dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
    } 

    cout << dp[1][n] - (s - dp[1][n]);

    return 0;
}