#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define name "PAL"

int const N = 209;
int const MOD = 1e9 + 7;

int n;
string s;

int dp[N][N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    n = s.size();
    s = " " + s;

    FOR(i, 1, n) dp[i][i] = 1;

    FORD(i, n, 1) FOR(j, i + 1, n)
    {
        int x = s[i] == s[j] ? (dp[i + 1][j - 1] + 1) % MOD : 0;

        Add(dp[i][j], dp[i + 1][j]);
        Add(dp[i][j], dp[i][j - 1]);
        Sub(dp[i][j], dp[i + 1][j - 1]);
        Add(dp[i][j], x);
    }

    cout << dp[1][n];
 
    return 0;
}