#include <bits/stdc++.h>

using namespace std;

int n;

long long nums[100005];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + 1 <= n - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    if (n % 2 == 1)
    {
        cout << nums[(n / 2) + 1];
    }
    else
    {
        cout << ((long double)nums[n / 2] / 2) + ((long double)nums[(n / 2) + 1] / 2);
    }
}