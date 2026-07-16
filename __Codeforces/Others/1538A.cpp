#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int nums[109];

int mi;
int ma;

int first;
int last;

int res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        mi = ma = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];

            if (nums[i] > nums[ma])
            {
                ma = i;
            }
            if (nums[i] < nums[mi])
            {
                mi = i;
            }
        }

        if (mi < ma)
        {
            first = mi;
            last = ma;
        }
        else
        {
            first = ma;
            last = mi;
        }

        if (first + 1 < n - last)
        {
            res = first + 1;
            res += min(last - first, n - last);
        }
        else
        {
            res = n - last;
            res += min(last - first, first + 1);
        }
        

        cout << res << '\n';
    }

    return 0;
}