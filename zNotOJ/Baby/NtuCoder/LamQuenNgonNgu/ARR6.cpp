#include <bits/stdc++.h>

using namespace std;

int n;

long long nums[102];

int res = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
            {
                res += 1;
            }
        }
    }

    cout << res;
}