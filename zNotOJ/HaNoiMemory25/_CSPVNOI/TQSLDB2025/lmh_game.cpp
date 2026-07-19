#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 209;
int const MOD = 1e9 + 7;

int n, m, k;
int dp[N][N][N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    FOR(x, 0, k) dp[0][0][x] = 1;

    FOR(i, 1, n) FOR(j, 0, m) FOR(x, 0, k)
    {
        if (j >= x) Add(dp[i][j][x], dp[i - 1][j - x][x]);
        if (x) Add(dp[i][j][x], dp[i][j][x - 1]);
    }

    cout << dp[n][m][k];

    return 0;
}