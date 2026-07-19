#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "COINS"

int const N = 1e6 + 5;

int k, l, m;
int n;

bool dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> k >> l >> m;

    FOR(i, 1, 1e6)
    {
        dp[i] |= !dp[i - 1];
        if (i - k >= 0) dp[i] |= !dp[i - k];
        if (i - l >= 0) dp[i] |= !dp[i - l];
    }

    FOR(i, 1, m)
    {
        cin >> n;
        cout << (char) ('A' + !dp[n]);
    }

    return 0;
}