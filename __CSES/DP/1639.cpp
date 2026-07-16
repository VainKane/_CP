#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;

int n, m;
string s1, s2;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    n = sz(s1); m = sz(s2);
    s1 = " " + s1;
    s2 = " " + s2;

    FOR(i, 1, n) 
    {
        dp[i][0] = i;
        FOR(j, 1, m)
        {
            dp[0][j] = j;
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }

    cout << dp[n][m];

    return 0;
}