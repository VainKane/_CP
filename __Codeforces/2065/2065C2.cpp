#include <bits/stdc++.h>

using namespace std;

bool Check(int a[], int b[], int n, int m)
{
    sort(b, b + m);

    a[0] = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1]) 
        {
            auto it = lower_bound(b, b + m, a[i] + a[i - 1]);
            if (it == b + m) return false;
            a[i] = *it - a[i];

            continue;
        }
        else if (a[i] > a[i - 1])
        {
            auto it = lower_bound(b, b + m, a[i] + a[i - 1]);
            if (it != b + m)
            {
                a[i] = min(a[i], *it - a[i]);
            }
        }
    }

    return true;
}

int t;

int n;
int m;

int a[(int)2e5 + 9];
int b[(int)2e5 + 9];

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
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        if (Check(a, b, n, m))
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