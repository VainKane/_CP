#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

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

int const N = 1e5 + 5;

int n, k;
int h[N], dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> h[i];

    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;

    FOR(i, 1, n) FOR(j, max(1, i - k), i - 1) mini(dp[i], dp[j] + abs(h[i] - h[j]));
    cout << dp[n];

    return 0;
}