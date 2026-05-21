#include <bits/stdc++.h>

using namespace std;

int n;

long long nums[200005];

int main()
{
    cin >> n;

    n *= 2;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (nums[j] < nums[j + 1])
            {
                long long temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' '; 
    }
}