#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool maxi(t &x, t const &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    return false;
}

int const N = 209;

int n;
string a;

int dp[N][N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> a;

    a = " " + a;

    FORD(i, n, 1) FOR(j, i, n) FOR(k, 0, n)
    {
        maxi(dp[i][j][k], dp[i][j - 1][0] + (k + 1) * (k + 1));

        FOR(u, i, j - 1) if (a[u] == a[j]) 
            maxi(dp[i][j][k], dp[u + 1][j - 1][0] + dp[i][u][k + 1]);
    }

    cout << dp[1][n][0];

    return 0;
}