#include <bits/stdc++.h>

using namespace std;

int n;
int a[109];
int dp[109][(int)1e4 + 10];

int s = 0;
int sum;

deque<int> mark1;
deque<int> mark2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
            {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i]];
            }
        }
    }

    for (int j = s / 2; j <= s; j++) 
    {
        if (dp[n][j])
        {
            sum = j;
            break;       
        }
    }

    int w = sum;

    for (int i = n; i >= 1; i--)
    {
        if (w >= a[i])
        {
            if (dp[i - 1][w - a[i]])
            {
                mark1.push_front(i);
                w -= a[i];
            }
        }
    }

    sort(mark1.begin(), mark1.end());

    for (int i = 1; i <= n; i++)
    {
        if (!binary_search(mark1.begin(), mark1.end(), i))
        {
            mark2.push_back(i);
        }
    }

    cout << abs(2 * sum - s) << '\n';
    for (auto val : mark1) cout << val << ' ';
    cout << '\n';
    for (auto val : mark2) cout << val << ' ';

    return 0;
}