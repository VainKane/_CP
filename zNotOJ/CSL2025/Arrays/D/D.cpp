#include <bits/stdc++.h>

using namespace std;

int n;
int q;

long long nums[(int)1e5 + 10];
long long d[(int)1e5 + 10];

int l;
int r;
int x;

int main()
{
    cin >> n >> q;

    d[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        d[i] = nums[i] - nums[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r >> x;

        l -= 1;
        r -= 1;

        d[l] += (long long)x;
        d[r + 1] -= (long long)x;
    }

    long long sum = d[0];

    cout << sum << ' ';

    for (int i = 1; i < n; i++)
    {
        sum += d[i];

        cout << sum << ' ';
    }


    return 0;
}
