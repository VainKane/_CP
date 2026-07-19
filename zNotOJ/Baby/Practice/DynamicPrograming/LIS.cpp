#include <bits/stdc++.h>

using namespace std;

int Search(int nums[], int target, int l, int r)
{
    int mid;
    int res = 1;

    while (l <= r)
    {
        mid = (r + l) / 2;

        int a = nums[mid];

        if (target > nums[mid] && nums[mid] != 0)
        {
            if (res < mid)
            {
                res = mid;
            }

            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return res;
}

int n;
int nums[(int)1e5 + 10];
int l[(int)1e5 + 10];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        l[i + 1] = INT_MAX;
    }

    l[1] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int x = Search(l, nums[i], 1, i - 1);

        if (l[x + 1] > nums[i])
        {
            l[x + 1] = nums[i];
        }

        if (res < x + 1)
        {
            res = x + 1;
        }
    }

    cout << res;
}