#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

long long nums[102];

int GCD(long long a, long long b)
{
    if (a * b == 0)
    {
        return a + b;
    }

    long long r = a % b;

    if (r == 0)
    {
        return b;
    }

    while (r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int count1 = 0;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long lcm = (nums[i] * nums[j]) / GCD(nums[i], nums[j]);

            if (j <= lcm && lcm <= k)
            {
                count1 += 1;
            }
        }
    }

    cout << count1;
}