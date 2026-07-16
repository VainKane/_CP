#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)

using namespace std;

bool Check(int a[], int n)
{
    for (int i = 0; i <= n / 2; i++)
    {
        if (2LL * (n - 1 - i) >= a[i]) return false;
    }

    for (int i = n / 2; i < n; i++)
    {
        if (2LL * i >= a[i]) return false;
    }

    return true;
}

int t;
int n;

int a[(int)5e5 + 10];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];

        if (Check(a, n)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}