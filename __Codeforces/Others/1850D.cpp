#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

int Solve(int a[], int n, int k)
{
    int length;
    int maxLength = 1;

    sort(a, a + n);

    for (int i = 1; i < n; i++)
    {
        length = 1;

        while (a[i] - a[i - 1] <= k && i < n)
        {
            length++;
            i++;
        }

        maxLength = max(maxLength, length);
    }

    return n - maxLength;
}

int t;

int n;
int k;

int a[(int)2e5 + 10];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++) cin >> a[i];

        cout << Solve(a, n, k) << '\n';
    }

    return 0;
}