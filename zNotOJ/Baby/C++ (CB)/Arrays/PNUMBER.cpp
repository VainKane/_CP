#include <bits/stdc++.h>

bool Check(long long n);


long long nums[100];

int n;
int count;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (Check(nums[i]) == true)
        {
            count += 1;
        }
    }

    std::cout << count;
}

bool Check(long long n)
{
    if (n <= 0)
    {
        return false;        
    }

    while (n > 0)
    {
        if (n % 10 != 6 && n % 10 != 8)
        {
            return false;
        }

        n /= 10;
    }

    return true;
}