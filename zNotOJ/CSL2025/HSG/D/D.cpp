#include <bits/stdc++.h>

using namespace std;

int Pow(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= a;
        }

        b /= 2;
        a *= a;
    }

    return res;
}

int Count(int n)
{
    int cnt = 0;

    while (n)
    {
        cnt++;
        n /= 10;
    }

    return cnt;
}



long long CountPairs(int nums[], long double s[], int n, long long x)
{
    long long res = 0;

    for (int i = 0; i < n; i++)
    {
        s[i] = (long double)(x - nums[i]) / Pow(10, Count(nums[i]));
    }

    for (int i = 0; i < n; i++)
    {
        res += (long long)(upper_bound(nums, nums + n, s[i]) - nums);
    }

    return res;
}

int n;
long long l;
long long r;

int nums[(int)1e5 + 10];
long double s[(int)1e5 + 10];

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    cout << CountPairs(nums, s, n, r) - CountPairs(nums, s, n, l - 1);


    return 0;
}
