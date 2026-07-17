#include <bits/stdc++.h>

using namespace std;

#define name "WORK"

int const N = 1e6 + 5;

int n;
int a[N];
int b[N];

int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];

    dp[1] = min(a[1], b[1]);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);
    }

    cout << dp[n];

    return 0;
}