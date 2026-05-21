#include <bits/stdc++.h>

using namespace std;

int Search(int nums[], int target, int l, int r)
{
    int mid;
    int res = -1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (nums[mid] < target)
        {
            if (mid > res)
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
        int pos = Search(l, nums[i], 0, i);

        if (l[pos + 1] > nums[i])
        {
            l[pos + 1] = nums[i];
        }

        if (res < pos + 1)
        {
            res = pos + 1;
        }
    }

    cout << res;

    return 0;
}
