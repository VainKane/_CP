#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define name "COUNTPL"

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;

int n;
string s;

int f[N][N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    n = s.size();
    s = " " + s;

    #define F(i, j) ((j) <= (i) ? 1 : f[i][j])

    FORD(i, n, 1) FOR(j, i, n)
        f[i][j] = F(i + 1, j - 1) & (s[i] == s[j]);

    FOR(i, 1, n) 
    {
        dp[i] = i;
        FOR(j, 0, i - 1) if (f[j + 1][i])
            mini(dp[i], dp[j] + 1);
    }

    cout << dp[n];  

    return 0;
}