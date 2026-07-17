#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

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

int const N = 1e5 + 5;

int n;
int dp[N][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        FOR(j, 1, 3)
        {
            int x; cin >> x;
            FOR(k, 1, 3) if (k != j)
                maxi(dp[i][j], dp[i - 1][k] + x);
        }
    }

    cout << max({dp[n][1], dp[n][2], dp[n][3]});

    return 0;
}