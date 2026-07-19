#include <bits/stdc++.h>

using namespace std;

double nums[110];

double average = 0;
double value = 0;


int n;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        average += nums[i];
    }

    average /= n;

    value = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (abs(average - value) > abs(average - nums[i]))
        {
            value = nums[i];
        }
    }

    std::cout << std::fixed << std::setprecision(2) << average << '\n' << value;
}