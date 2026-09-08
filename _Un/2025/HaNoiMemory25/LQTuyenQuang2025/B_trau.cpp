#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2009;

int n, m, c;
int a[N][N];
long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("B.inp", "r", stdin);

    cin >> m >> n >> c;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    memset(dp, -0x3f, sizeof dp);

    dp[1][1] = 0;

    FOR(i, 1, m) FOR(j, 1, n) 
    {
        FOR(u, 1, i - 1) maxi(dp[i][j], dp[u][j] + abs(a[i][j] - a[u][j]) - c);
        FOR(v, 1, j - 1) maxi(dp[i][j], dp[i][v] + abs(a[i][j] - a[i][v]) - c);
    }

    cout << dp[m][n] << '\n';

    return 0;
}