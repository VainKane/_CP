#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

int Solve(int a[], int n, int k)
{
    int sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        sum += a[i];

        if (sum == k)
        {
            return 0;
        }
        else if (sum > k)
        {
            return k - (sum - a[i]);
        }
    }

    return k - sum;
}

int t;

int n;
int k;

int a[59];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n); 

        cout << Solve(a, n, k) << '\n';
    }

    return 0;
}