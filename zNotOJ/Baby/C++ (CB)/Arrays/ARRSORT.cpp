#include <bits/stdc++.h>


long double nums[100];

int n;

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        int minIndex = i;

        for (int j = i; j < n; j++)
        {
            if (nums[minIndex] > nums[j])
            {
                minIndex = j;
            }
        }

        std::swap(nums[minIndex], nums[i]);
    }


    for (int i = 0; i < n; i++)
    {
        std::cout << nums[i] << ' ';
    }

    std::cout << '\n';

    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << nums[i] << ' ';
    }
}


