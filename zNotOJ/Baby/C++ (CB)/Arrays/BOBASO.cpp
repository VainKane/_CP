#include <bits/stdc++.h>

bool Check(long long a, long long b, long long c);


long long nums[100];

int n;
int count = 0;
long long perimeter = 0;

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
            for (int k = j + 1; k < n; k++)
            {
                if (Check(nums[i], nums[j], nums[k]) == true)
                {
                    count += 1;

                    if (perimeter < nums[i] + nums[j] + nums[k])
                    {
                        perimeter = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
    }

    std::cout << count << ' ' << perimeter;
}

bool Check(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    else if ((a >= b + c) || (b >= c + a) || (c >= b + a))
    {
        return false;
    }

    return true;
}