#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const N = 1e5 + 5;

int n;
int k;
int a[N];
int dp[10009];

int res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    freopen("23E.inp", "r", stdin);
    freopen("23E.ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    res = dp[0] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j] > i) continue;

            dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }

        res = (res + dp[i]) % MOD;
    }

    cout << res;

    return 0;
}