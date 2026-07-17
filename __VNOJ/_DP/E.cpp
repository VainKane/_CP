#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class X, class Y>
    bool mini(X &x, Y const &y)
    {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }

int const N = 1e2 + 5;

int n, s;
int w[N], v[N];

long long dp[N][(int)1e5 + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    FOR(i, 1, n) cin >> w[i] >> v[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    FOR(i, 1, n) FOR(j, 0, 1e5) 
    {
        dp[i][j] = dp[i - 1][j];
        if (j >= v[i]) mini(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
    }

    FORD(j, 1e5, 1) if (dp[n][j] <= s) 
    {
        cout << j;
        exit(0);
    }

    return 0;
}