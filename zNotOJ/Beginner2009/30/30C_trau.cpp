#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int k;

int a[N];
int dp[N];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("30C.inp", "r", stdin);
    freopen("30C.ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (abs(a[i] - a[j]) >= k)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}