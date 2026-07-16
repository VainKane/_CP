#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)

using namespace std;

bool Check(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1]) return false;

        a[i] -= a[i - 1];
        a[i - 1] = 0;
    }
    
    return true;
}

int t;

int n;
int a[(int)2e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

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