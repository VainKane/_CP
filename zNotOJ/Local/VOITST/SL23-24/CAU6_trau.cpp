#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU6"

int const N = 2009;
int const MOD = 1e9 + 7;

int n, k;
int dp[N][N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    k--;
    
    dp[0][0] = 1;
    FOR(i, 1, n) 
    {
        FOR(j, 0, k) Add(dp[i][0], dp[i - 1][j]);
        FOR(j, 1, k) Add(dp[i][j], dp[i - 1][j - 1]);
    }

    int res = 0;
    FOR(j, 0, k) Add(res, dp[n][j]);
    cout << res;

    return 0;
}