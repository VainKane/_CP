#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[(int)1e5 + 10];
int b[(int)1e5 + 10];

int main()
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

    int i = 0;
    int j = 0;
    
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << ' ';
            i++;
        }
        else
        {
            cout << b[j] << ' ';
            j++;
        }
    }

    while (i < n)
    {
        cout << a[i] << ' ';
        i++;
    }
    while (j < m)
    {
        cout << b[j] << ' ';
        j++;
    }

    return 0;
}   