#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "NTH"

int const N = 1e3 + 10;

int n, m;
int a[N];

long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    a[0] = -1;
    a[n + 1] = m;

    FOR(l, 2, n + 1) FOR(i, 0, n - l + 1)
    {
        int j = i + l;

        if (a[j] - a[i] - 1 < 2) 
        {
            dp[i][j] = 0;
            continue;
        }

        dp[i][j] = 1e17;
        FOR(k, i + 1, j - 1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[j] - a[i] - 1); 
    }

    cout << dp[0][n + 1];

    return 0;
}