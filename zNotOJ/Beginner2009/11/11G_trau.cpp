#include <bits/stdc++.h>

using namespace std;

int const N = 5009;

int n;

int a[N];
int b[N];
int dp[N][N * 6];

int s = 0;
int sum = 0;

int res = INT_MAX;
vector<int> mark;

// code wa(82p)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("11G.inp", "r", stdin);
    // freopen("11G.ans", "w", stdout);
    
    cin >> n;

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        s += max(a[i], b[i]);
        sum += a[i] + b[i];
    }

    dp[1][a[1]] = 0;
    dp[1][b[1]] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j >= a[i] && j >= b[i] && dp[i - 1][j - a[i]] != -1 && dp[i - 1][j - b[i]] != -1)
            {
                dp[i][j] = min(dp[i - 1][j - a[i]], dp[i - 1][j - b[i]] + 1);
                continue;
            }
            else if (j >= a[i] && dp[i - 1][j - a[i]] != -1)
            {
                dp[i][j] = dp[i - 1][j - a[i]];
            }
            else if (j >= b[i] && dp[i - 1][j - b[i]] != -1)
            {
                dp[i][j] = dp[i - 1][j - b[i]] + 1;
            }
        }
    }

    int k;

    for (int j = sum; j >= 1; j--) 
    {
        if (dp[n][j] != -1) 
        {
            int d = abs(j - (sum - j));
            if (d < res || (d == res && dp[n][j] < dp[n][k])) 
            {
                res = d;
                k = j;
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (k >= a[i] && k >= b[i] && dp[i - 1][k - a[i]] != -1 && dp[i - 1][k - b[i]] != -1)
        {
            if (dp[i - 1][k - b[i]] + 1 < dp[i - 1][k - a[i]])
            {
                mark.push_back(i);
                k -= b[i];
            }
            else k -= a[i];
        }
        else if (k >= a[i] && dp[i - 1][k - a[i]] != -1)
        {
            k -= a[i];
        }
        else if (k >= b[i] && dp[i - 1][k - b[i]] != -1)
        {
            mark.push_back(i);
            k -= b[i];
        }
        else break;
    }
    
    cout << res << '\n';    
    cout << mark.size() << '\n';
    for (auto val : mark) cout << val << '\n';
    
    return 0;
}