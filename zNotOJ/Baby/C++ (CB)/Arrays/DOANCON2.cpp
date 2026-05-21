#include <bits/stdc++.h>

long long nums[1000000];

int n;
int length = 1;
int maxLength = 1;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i + 1 < n; i++)
    {
        if (nums[i] * nums[i + 1] < 0)
        {
            length += 1;
        }
        else
        {
            if (maxLength < length)
            {
                maxLength = length;
            }

            length = 1;
        }

        if (maxLength < length)
        {
            maxLength = length;
        }
    }

    std::cout << maxLength;
}