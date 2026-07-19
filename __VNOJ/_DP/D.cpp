#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = b; i <= _b; i++)

template <class X, class Y>
    bool maxi(X &x, Y const &y)
    {
        if (x < y)
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

    FOR(i, 1, n) FOR(j, 0, s)
    {
        dp[i][j] = dp[i - 1][j];
        if (j >= w[i]) maxi(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    }

    long long res = 0;
    FOR(j, 1, s) maxi(res, dp[n][j]);
    cout << res;

    return 0;
}