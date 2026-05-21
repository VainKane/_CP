#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 505;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;

char a[N][N];
int dp[2][N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        if (n == 0) return 0;
        FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

        int nxt = 0, cur = 1;

        memset(dp[nxt], 0, sizeof dp[nxt]);
        dp[nxt][1][n] = (a[1][1] == a[n][n]);  

        FOR(k, 0, n - 2)
        {
            swap(cur, nxt);
            memset(dp[nxt], 0, sizeof dp[nxt]);

            FOR(i1, 1, n)
            {
                int j1 = k - i1 + 2;
                if (j1 < 1) break;
                FOR(i2, i1, n)
                {
                    int j2 = 2 * n - k - i2;
                    if (j2 < j1) break;

                    int x = dp[cur][i1][i2];

                    Add(dp[nxt][i1][i2], x * (a[i1][j1 + 1] == a[i2][j2 - 1]));
                    Add(dp[nxt][i1][i2 - 1], x * (a[i1][j1 + 1] == a[i2 - 1][j2]));
                    Add(dp[nxt][i1 + 1][i2], x * (a[i1 + 1][j1] == a[i2][j2 - 1]));
                    Add(dp[nxt][i1 + 1][i2 - 1], x * (a[i1 + 1][j1] == a[i2 - 1][j2])); 
                }
            }
        }

        int res = 0;
        FOR(i, 1, n) Add(res, dp[nxt][i][i]);

        cout << res << '\n';
    }

    return 0;
}