#include <bits/stdc++.h>

int n;

long double nums[100];

long double sum = 0;
long double positiveSum = 0;
long double negativeSum = 0;
long double evenSum = 0;
long double oddSum = 0;

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        if (nums[i] > 0)
        {
            positiveSum += nums[i];
        }
        else
        {
            negativeSum += nums[i];
        }


        if (i % 2 == 1)
        {
            evenSum += nums[i];
        }
        else
        {
            oddSum += nums[i];
        }
    }

    std::cout << sum << ' ' << negativeSum << ' ' << positiveSum << ' ' << evenSum << ' '<< oddSum;
}
