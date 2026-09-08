#include <bits/stdc++.h>

using namespace std;

int n;
int x;

int s;

int nums[(int)1e4 + 10];

long long cnt = 0;
long long sum;

int l;
int r;

int main()
{
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    for (int l2 = 0; l2 + 2 < n; l2++)
    {
        l = l2 + 1;
        r = n - 1;

        while (l != r)
        {
            sum = nums[l2] + (long long)nums[l] + nums[r];

            if (sum <= x)
            {
                cnt += r - l;
                l++;
            }
            else
            {
                r--;
            }
        }
    }


    cout << cnt;

    return 0;
}
