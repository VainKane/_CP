#include <bits/stdc++.h>

using namespace std;

int n;
int nums[102][102];

long long sum = 0;
long long res = 0;

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
        for (int j = 0; j <= i; j++)
        {
            int a = n - 1 - j;
            int b = i - j;

            if (a < n && b < n)
            {
                sum += nums[a][b];
            }
        }

        if (sum > res)
        {
            res = sum;
        }

        sum = 0;
    }

    cout << res;
}