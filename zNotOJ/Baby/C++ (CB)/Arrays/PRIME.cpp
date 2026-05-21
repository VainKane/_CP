#include <bits/stdc++.h>

bool Check(long long n);


long long nums[100];

int n;
int count = 0;
long long sum = 0;

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
            sum += nums[i];
        }
    }

    std::cout << count << ' ' << sum;
}

bool Check(long long n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}