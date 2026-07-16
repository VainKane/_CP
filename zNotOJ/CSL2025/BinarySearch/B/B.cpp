#include <bits/stdc++.h>

using namespace std;

int FirstPos(int nums[], int tar, int l, int r)
{
    int mid;
    int res = -1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (nums[mid] == tar)
        {
            res = mid;
            r = mid - 1;
        }
        else if (nums[mid] < tar)
        {
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
int sorted[2][(int)1e5 + 10];

int main()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sorted[0][i] = nums[i];
    }

    sort(sorted[0], sorted[0] + n);
    memset(sorted[1], -1, sizeof sorted[1]);

    for (int i = 0; i < n; i++)
    {
        int pos = FirstPos(sorted[0], nums[i], 0, n - 1);
        while (sorted[1][pos] != -1) pos++;
        sorted[1][pos] = i;
    }

//    for (int i = 0; i < n; i++) cout << sorted[0][i] << ' ';
//    cout << '\n';
//    for (int i = 0; i < n; i++) cout << sorted[1][i] << ' ';


    while (q--)
    {
        int x;
        int l;
        int r;

        int cnt = 0;

        cin >> l >> r >> x;
        l--;
        r--;

        int pos = FirstPos(sorted[0], x, 0, n - 1);

        while (sorted[0][pos] == x)
        {
            if (sorted[1][pos] >= l && sorted[1][pos] <= r) cnt++;
            pos++;
        }

        cout << cnt << '\n';
    }

    return 0;
}
