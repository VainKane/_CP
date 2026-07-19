#include <bits/stdc++.h>

using namespace std;

int n;
long long result = 0;

long long nums[100009];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);


    int count = 0;

    for (int i = 0; i + 1 < n; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            count += 1;
            result += count;
        }
        else
        {
            count = 0;
        }
    }    

    cout << result;
}