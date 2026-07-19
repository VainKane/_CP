#include <bits/stdc++.h>

using namespace std;

long long Solve(long long k)
{
    long long l = 1;
    long long r = 2e18;

    long long mid;

    long long res;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (mid == k + (int)sqrtl(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else if (mid < k + (int)sqrt(mid))
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

int t;
long long k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> k;

        cout << Solve(k) << '\n';
    }

    return 0;
}