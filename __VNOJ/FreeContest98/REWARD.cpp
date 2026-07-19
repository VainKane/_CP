#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int a[N];

long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -0x3f, sizeof dp);
    dp[1] = max(0, a[1]);
    dp[2] = max({0, a[1], a[2], a[1] + a[2]});
    dp[0] = 0;

    for (int i = 3; i <= n; i++)
    {
        long long s1 = dp[i - 2] + a[i];
        long long s2 = dp[i - 1];
        long long s3 = dp[i - 3] + a[i] + a[i - 1];

        dp[i] = max({s1, s2, s3, 1ll * a[i]});
    }

    cout << dp[n];

    return 0;
}