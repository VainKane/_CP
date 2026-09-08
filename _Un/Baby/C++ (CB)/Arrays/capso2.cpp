#include <bits/stdc++.h>

long long nums[1000];

int n;
int x;
int count = 0;

int main()
{
    std::cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == x)
            {
                count += 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        x - nums[i];
    }

    std::cout << count;
}

