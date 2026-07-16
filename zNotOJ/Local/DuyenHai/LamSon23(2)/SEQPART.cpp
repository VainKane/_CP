#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SEQPART"

int const N = 8009;

int n, k;

int a[N];
long long pre[N];

long long dp[N][809];

long long Get(int l, int r)
{
    if (l > r) return 0;
    return pre[r] - pre[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];

    memset(dp, 0x3f, sizeof dp);

    FOR(i, 1, n) dp[i][1] = 1ll * pre[i] * i;
    FOR(i, 2, n) FOR(j, 2, min(i, k)) FOR(k, j - 1, i - 1)
    {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + 1ll * Get(k + 1, i) * (i - k));
        // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    }

    cout << dp[n][k];

    return 0;
}