#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "BLAST"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2009;

int n, m, k;
string a, b;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> a >> b;
    cin >> k;

    n = a.size();
    m = b.size();

    a = " " + a;
    b = " " + b;

    FOR(i, 1, n) dp[i][0] = i * k;
    FOR(j, 1, m) dp[0][j] = j * k;

    FOR(i, 1, n) FOR(j, 1, m)
    {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + k;
        mini(dp[i][j], dp[i - 1][j - 1] + abs(a[i] - b[j]));
    }

    cout << dp[n][m];

    return 0;
}