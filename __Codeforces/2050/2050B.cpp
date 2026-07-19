#include <bits/stdc++.h>

using namespace std;

void Add(int i, int a[], int n, int avg)
{
    if (i >= n - 2) return;

    if (a[i + 2] < avg)
    {
        Add(i + 2, a, n, avg);
    }

    int d = avg - a[i];
    a[i] += d;
    a[i + 2] -= d;
}

bool Solve(int a[], int n, int avg)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != avg)
        {
            if (a[i] > avg)
            {
                int d = a[i] - avg;
                a[i] -= d;
                a[i + 2] += d;
            }
            else
            {
                Add(i, a, n, avg);
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1]) return false;
    }

    return true;
}

int n;
int a[(int)2e5 + 10];

long long avg = 0;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        avg = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            avg += 1LL * a[i];
        }

        if (avg % n != 0) cout << "NO\n";
        else
        {
            avg /= n;
            if (Solve(a, n, avg)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}