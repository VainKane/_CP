#include <bits/stdc++.h>

using namespace std;

int f;
int v;

int a[109][109];
int dp[109][109];

pair<int, int> b[109][109];

deque<int> mark;
int lastPos;

// code 60 diem

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("12B.inp", "r", stdin);
    // freopen("12B.ans", "w", stdout);

    cin >> f >> v;

    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= v; j++) dp[1][j] = a[1][j];

    for (int i = 2; i <= f; i++)
    {
        for (int j = i; j <= v; j++)
        {
            dp[i][j] = INT_MIN;

            for (int m = 1; m <= j; m++)
            {
                for (int n = m + 1; n <= j; n++)
                {
                    if (dp[i][j] < dp[i - 1][m] + a[i][n])
                    {
                        b[i][j] = {i - 1, m};
                        dp[i][j] = dp[i - 1][m] + a[i][n];

                        lastPos = n;
                    }
                }
            }
        }
    }

    pair<int, int> pos = b[f][v];

    while (pos.first != 0 && pos.second != 0)
    {
        mark.push_front(pos.second);
        pos = b[pos.first][pos.second];
    }
    mark.push_back(lastPos);

    cout << dp[f][v] << '\n';
    for (auto val : mark) cout << val << ' ';

    return 0;
}