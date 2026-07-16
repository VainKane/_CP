#include <bits/stdc++.h>

using namespace std;

int n;

long long nums[100005];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;
        
        if (value % 2 == 0)
        {
            value /= 2;
        }
        else
        {
            value += 1;
        }

        nums[i] = value;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < n - i; j++)
        {
            if (nums[j] > nums[j + 1])
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