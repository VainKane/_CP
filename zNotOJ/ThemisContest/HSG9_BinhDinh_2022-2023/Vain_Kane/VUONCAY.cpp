#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int sum;

long long nums[105][105];

int main()
{
    cin >> m >> n;

    sum = n * (m + 1) + m * (n + 1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
            {
                if (nums[i][j] == nums[i][j + 1])
                {
                    sum -= 1;
                }
            }


            if (i != m - 1)
            {
                if (nums[i][j] == nums[i + 1][j])
                {
                    sum -= 1;
                }
            }

        }
    }

    cout << sum;
}
