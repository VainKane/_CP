#include <bits/stdc++.h>

long double nums[100];

int n;
long double x;

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            std::cout << nums[i] << " ";
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > 0)
        {
            std::cout << nums[i] << '\n';
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
        {
            std::cout << i + 1 << " ";
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] == x)
        {
            std::cout << i + 1;
            break;
        }
    }
}


