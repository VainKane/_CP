#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int t;
int res;

int main()
{
    cin >> n >> k;

    t = 4 * 60 - k;

    for (int i = 1; i <= n; i++)
    {
        t -= i * 5;

        if (t < 0)
        {
            res = i - 1;
            break;
        }
        else if (i == n)
        {
            res = n;
            break;
        }
    }

    cout << res;

    return 0;
}