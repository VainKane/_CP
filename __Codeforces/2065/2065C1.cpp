#include <bits/stdc++.h>

using namespace std;

bool Check(int a[], int n, int m)
{
    a[0] = min(a[0], m - a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            a[i] = max(a[i], m - a[i]);

            if (a[i] < a[i - 1])
            {
                return false;
            }

            continue;
        }
        else if (a[i] > a[i - 1])
        {
            if (m - a[i] >= a[i - 1])
            {
                a[i] = min(a[i],m - a[i]);
            }
        }
    }

    return true;
}

int t;

int n;
int m;

int a[(int)2e5 + 9];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cin >> m;

        if (Check(a, n, m))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}