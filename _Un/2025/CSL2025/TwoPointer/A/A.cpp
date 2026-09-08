#include <bits/stdc++.h>

using namespace std;

int n;
int q;
int x;

int nums[(int)1e5 + 100];


int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> q;

    sort(nums, nums + n);

    while (q--)
    {
        cin >> x;

        int l = 0;
        int r = n - 1;

        int cnt = 0;

        while (l < r)
        {
            long long sum = (long long)nums[l] + nums[r];

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

        cout << cnt << '\n';
        cnt = 0;
    }



    return 0;
}
