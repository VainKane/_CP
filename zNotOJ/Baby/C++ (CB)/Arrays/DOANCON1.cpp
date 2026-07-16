#include <bits/stdc++.h>

long long nums[1000000];

int n;
int length = 1;
int maxLength = 0;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i + 1 < n; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            length += 1;
        }
        else
        {
            if (maxLength < length && length != 1)
            {
                maxLength = length;
            }

            length = 1;
        }

        if (maxLength < length && length != 1)
        {
            maxLength = length;
        }
            
    }

    std::cout << maxLength;
}