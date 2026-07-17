#include <bits/stdc++.h>

using namespace std;

int n;
long long times;
int k;

long long nums[102];

long long res;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> times;

    for (int i = 0; i < times; i++)
    {
        cin >> k;

        res = nums[0];

        for (int i = 0; i < k; i++)
        {
            if (nums[i] < res)
            {
                res = nums[i];
            }
        }

        cout << res << '\n';
    }
}