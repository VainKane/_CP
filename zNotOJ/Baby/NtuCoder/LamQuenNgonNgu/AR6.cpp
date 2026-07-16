#include <bits/stdc++.h>

using namespace std;

int n;

int nums[102];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < n - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }
}