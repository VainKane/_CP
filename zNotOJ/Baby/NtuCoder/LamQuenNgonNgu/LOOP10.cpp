#include <bits/stdc++.h>

using namespace std;

bool Check(long long nums[], int l, int r, long long target)
{
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (target == nums[mid])
        {
            return true;
        }
        else if (target < nums[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return false;
}

long long nums[1000006];

int i = 0;

long long value;

int main()
{
    while (cin >> value)
    {
        nums[i] = value;
        i++;
    }

    sort(nums, nums + i);

    if (Check(nums, 0, i - 1, (long long)2004))
    {
        cout << 2004;
    }
    else
    {
        cout << -1;
    }
}