#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 20;

long long a, b;
int x[N];
long long dp[N][2][150];

long long Get(long long val)
{
    long long tmp = val;
    int n = 0;
    
    while (tmp)
    {
        x[n++] = tmp % 10;
        tmp /= 10;
    }

    reverse(x, x + n);

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    REP(i, n) FOR(r, 0, 1) FOR(sum, 0, i * 9) if (dp[i][r][sum])
    {
        int lim = r ? 9 : x[i];
        FOR(d, 0, lim) dp[i + 1][r | (d < lim)][sum + d] += dp[i][r][sum];
    }
        
    long long res = 0;
    FOR(sum, 0, 9 * n) res += (dp[n][0][sum] + dp[n][1][sum]) * sum;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    cout << Get(b) - Get(a - 1);

    return 0;
}