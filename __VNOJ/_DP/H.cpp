#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1009;
int const MOD = 1e9 + 7;

int m, n;
bool a[N][N];
int dp[N][N];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        char x; cin >> x;
        a[i][j] = (x == '.');
    }

    dp[1][1] = a[1][1];

    FOR(i, 1, m) FOR(j, 1, n)
    {
        if (a[i + 1][j]) Add(dp[i + 1][j], dp[i][j]);
        if (a[i][j + 1]) Add(dp[i][j + 1], dp[i][j]); 
    }
    
    cout << dp[m][n];

    return 0;
}