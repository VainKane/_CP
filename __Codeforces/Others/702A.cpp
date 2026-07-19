#include <bits/stdc++.h>

using namespace std;

int n;
int nums[(int)1e5 + 10];
int length[(int)1e5 + 10];

int res = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        length[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            length[i] = length[i - 1] + 1;

            if (length[i] > res)
            {
                res = length[i];
            }
        }
    }

    cout << res;

    return 0;
}