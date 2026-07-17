#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int w[(int)1e5 + 10];
int v[109];

long long dp[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 0; i <= m; i++) dp[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j >= w[i])
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[m];

    return 0;
}
