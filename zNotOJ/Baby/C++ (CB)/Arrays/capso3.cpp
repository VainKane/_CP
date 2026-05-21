#include <bits/stdc++.h>

bool Check(long long n);


long long nums[1000];

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
        for (int j = i + 1; j < n; j++)
        {
            if (Check(nums[i] + nums[j]) == true)
            {
                count += 1;

            }
        }
    }
    
    std::cout << count;
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