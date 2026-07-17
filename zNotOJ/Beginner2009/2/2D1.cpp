#include <bits/stdc++.h>

using namespace std;

int n;

int a[(int)1e5 + 10];

int res = INT_MIN;
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        res = max(res, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << res;

    return 0;
}