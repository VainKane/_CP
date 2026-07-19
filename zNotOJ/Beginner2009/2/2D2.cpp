#include <bits/stdc++.h>

using namespace std;

int Kadane(int a[], int n)
{
    int sum = 0;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        res = max(res, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return res;
}

int n;
int a[(int)1e5 + 10];
int b[(int)1e5 + 10];

int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = -a[i];
        sum += a[i];
    }

    cout << max(Kadane(a, n), sum + Kadane(b, n));

    return 0;
}