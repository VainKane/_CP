#include <bits/stdc++.h>

using namespace std;

int Solve(int a[], int n)
{
    sort(a, a + n);

    if (a[0] > 1) return 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1) return a[i - 1] + 1;
    }

    return a[n - 1] + 1;
}

int n;
int a[3009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    cout << Solve(a, n);

    return 0;
}