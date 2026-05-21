#include <bits/stdc++.h>

using namespace std;

int Search(int nums[], int target, int l, int r)
{
    int mid;
    int res = -1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (nums[mid] <= target)
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
int q;
int nums[(int)1e5 + 10];

int main()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums, nums + n);

    while (q--)
    {
        int x;
        cin >> x;

        cout << Search(nums, x, 0, n - 1) + 1 << '\n';
    }

//    for (int i = 0; i < n; i++) cout << nums[i] << ' ';
//
//    cout << Search(nums, q, 0, n - 1);

    return 0;
}
