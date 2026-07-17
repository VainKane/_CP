#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

int nums[(int)1e5 + 10];

long long cnt = 0;
long long sum = 0;

int r = 0;
int l = 0;

int r1 = -1;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sum = nums[0];

    while (l < n && r < n)
    {
        while (sum <= k && l < n && r < n)
        {
            r++;
            sum += (long long)nums[r];
        }

        cnt += (long long)( (r - 1 - l + 1 + 1) * (r - 1 - l + 1) ) / 2;

        if (r1 >= l)
        {
            cnt -= (long long)( (r1 - l + 1 + 1) * (r1 - l + 1) ) / 2;
        }

        r1 = r - 1;

        while (nums[r] > k)
        {
            r++;
            sum += (long long)nums[r];
        }

        while (sum > k)
        {
            sum -= (long long)nums[l];
            l++;
        }
    }

    cout << cnt;

    return 0;
}
