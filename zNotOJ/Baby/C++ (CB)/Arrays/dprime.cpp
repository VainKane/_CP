#include <bits/stdc++.h>

int Sum(long long n);
bool Check(long long n);


long long nums[1000];
long long result[1000];

int n;
int count = 0;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (Check(nums[i]) && Check(Sum(nums[i])))
        {
            result[count] = nums[i];
            count += 1;
        }
    }

    std::cout << count << '\n';

    for (int i = 0; i < count; i++)
    {
        std::cout << result[i] << ' ';
    }

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

int Sum(long long n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

