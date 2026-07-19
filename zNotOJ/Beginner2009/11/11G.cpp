#include <bits/stdc++.h>

using namespace std;

int const N = 3009;

int n;

int a[N];
int b[N];
int dp[N][N * 6];

int s = 0;
int sum = 0;

int res = INT_MAX;
pair<int, int> c[N][N * 6];
bool mark[N][N * 6];

vector<int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("11G.inp", "r", stdin);
    // freopen("11G.out", "w", stdout);
    
    cin >> n;

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        s += max(a[i], b[i]);
        sum += a[i] + b[i];
    }

    dp[1][a[1]] = 0;

    if (a[1] != b[1])
    {
        dp[1][b[1]] = 1;
        mark[1][b[1]] = true;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j >= a[i] && j >= b[i] && dp[i - 1][j - a[i]] != -1 && dp[i - 1][j - b[i]] != -1)
            {
                if (dp[i - 1][j - b[i]] + 1 < dp[i - 1][j - a[i]])
                {
                    c[i][j].first = i - 1;
                    c[i][j].second = j - b[i];
                    mark[i][j] = true;

                    dp[i][j] = dp[i - 1][j - b[i]] + 1;
                }
                else
                {
                    c[i][j].first = i - 1;
                    c[i][j].second = j - a[i];

                    dp[i][j] = dp[i - 1][j - a[i]];
                }
                continue;
            }
            else if (j >= a[i] && dp[i - 1][j - a[i]] != -1)
            {
                dp[i][j] = dp[i - 1][j - a[i]];

                c[i][j].first = i - 1;
                c[i][j].second = j - a[i];
            }
            else if (j >= b[i] && dp[i - 1][j - b[i]] != -1)
            {
                dp[i][j] = dp[i - 1][j - b[i]] + 1;

                c[i][j].first = i - 1;
                c[i][j].second = j - b[i];
                mark[i][j] = true;
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

    pair<int, int> pos = c[n][k];

    while (pos.first != 0 && pos.second != 0)
    {
        if (mark[pos.first][pos.second]) m.push_back(pos.first);
        pos = c[pos.first][pos.second];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << c[i][j].first << ' ' << c[i][j].second << ' ' << mark[i][j] << " | ";
    //     }
    //     cout << '\n';
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << mark[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    cout << res << '\n';;    
    cout << m.size() << '\n';
    for (auto val : m) cout << val << '\n';
    
    return 0;
}