#include <bits/stdc++.h>

using namespace std;

long long Cal(int a[], int n, long long sum, long long x)
{
    long long t[(int)2e5 + 10];
    long long k[(int)2e5 + 10];
    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
        t[i] = sum - x - a[i];
        k[i] = sum - x;
    }

    sort(t, t + n);
    sort(k, k + n);

    for (int i = 0; i < n; i++)
    {
        cnt += 1LL * (upper_bound(t, t + n, a[i]) - t);
        if (upper_bound(k, k + n, 2 * a[i]) - k == n) cnt--;

        // cout << i << ' ' << upper_bound(t, t + n, a[i]) - t << ' ' << upper_bound(k, k + n, 2 * a[i]) - k << '\n';
    }

    return cnt / 2;
}

int t;

int n;
long long x;
long long y;

long long sum;

int a[(int)2e5 + 10];

int cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> y;

        sum = 0;

        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            sum += 1LL * a[i];
        }

        cout << Cal(a, n, sum, y) - Cal(a, n, sum, x - 1) << '\n';       
    }

    return 0;
}