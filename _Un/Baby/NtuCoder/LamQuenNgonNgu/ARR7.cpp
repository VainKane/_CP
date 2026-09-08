#include <bits/stdc++.h>

using namespace std;

int n;

long long nums[102];

long long sum = 0;
long long res = 0;

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
            sum = nums[i] * nums[i] + nums[j] * nums[j];

            if (sum > res)
            {
                res = sum;
            }
        }
    }

    cout << res;
}