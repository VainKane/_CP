#include <bits/stdc++.h>

long long nums[1000];

int n;
long long x;
int count = 0;

int main()
{
    std::cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i + 1 < n; i++)
    {
        if (nums[i] + nums[i + 1] == x)
        {
            count += 1;
        }
    }

    std::cout << count;
}