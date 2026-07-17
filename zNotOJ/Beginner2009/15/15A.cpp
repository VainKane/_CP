#include <bits/stdc++.h>

using namespace std;

int n;
int t[2009];
int r[2009];

int dp[2009];
bool mark[2009];
int b[2009];
deque<int> k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i < n; i++) cin >> r[i];

    dp[1] = t[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;

        if (dp[i] > dp[i - 1] + t[i])
        {
            b[i] = i - 1;
            mark[i] = 0;
            dp[i] = dp[i - 1] + t[i];
        }
        if (dp[i] > dp[i - 2] + r[i - 1])
        {
            b[i] = i - 2;
            mark[i] = 1;
            dp[i] = dp[i - 2] + r[i - 1];
        }
    }

    int pos = n;
    while (pos)
    {
        if (mark[pos]) k.push_front(pos);
        pos = b[pos];
    }

    cout << dp[n] << '\n';
    if (k.size() == 0) cout << 0;
    else for (auto val : k) cout << val << ' ';

    return 0;
}