#include <bits/stdc++.h>

long long nums[100000];
long long pre[100000];
long long sum = 0;

int n;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        pre[i] = sum + nums[i];
        sum = pre[i];
    }

    sum = nums[0];

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            if (pre[r] - pre[l - 1] > sum)
            {
                sum = pre[r] - pre[l - 1];
            }
        }
    }

    std::cout << sum;
}