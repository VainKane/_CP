#include <bits/stdc++.h>

long double nums[100];

int n;

long double min;
long double max;

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    max = min = nums[0];


    for (int i = 0; i < n; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }

        if (min > nums[i])
        {
            min = nums[i];
        }
    }

    std::cout << max << ' ' << min;
}