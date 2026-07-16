#include <bits/stdc++.h>

using namespace std;

int n;

int nums[102][102];

long long dig[202];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i < 2 * n - 1; i++)
    {
        dig[i] = 0;
    }

    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i <= n - 1)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                dig[i] += nums[j][i - j];
            }

        }
        else
        {
            for (int j = 1; j <= i - 1; j++)
            {
                int a = j;
                int b = n - j;
                dig[i] += nums[i - n + j][n - j];
            }
        }
    }

    sort(dig, dig + 2 * n - 1);

    cout << dig[2 * n - 2];

}