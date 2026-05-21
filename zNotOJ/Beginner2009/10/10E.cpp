#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[(int)2e5 + 10];

long long dp[(int)2e5 + 10][2];

void Cal(int pos, long long cost, int x, int y, long long &d0, long long &d1)
{
    if (x <= pos && y <= pos)
    {
        d0 = min(d0, cost + pos - x);
        d1 = min(d1, cost + pos - x + y - x);
    }
    else if (x >= pos && y >= pos)
    {
        d0 = min(d0, cost + y - pos + y - x);
        d1 = min(d1, cost + y - pos); 
    }
    else
    {
        d0 = min(d0, cost + y - pos + y - x);
        d1 = min(d1, cost + pos - x + y - x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    dp[1][0] = a[1].second - 1 + (a[1].second - a[1].first);
    dp[1][1] = a[1].second - 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = LLONG_MAX;
        Cal(a[i - 1].first, dp[i - 1][0], a[i].first, a[i].second, dp[i][0], dp[i][1]);
        Cal(a[i - 1].second, dp[i - 1][1], a[i].first, a[i].second, dp[i][0], dp[i][1]);
    }

    // for (int i = 1; i <= n; i++) cout << dp[i][0] << ' ' << dp[i][1] << '\n';

    cout << min(dp[n][0] + n - a[n].first, dp[n][1] + n - a[n].second) + n - 1;

    return 0;
}