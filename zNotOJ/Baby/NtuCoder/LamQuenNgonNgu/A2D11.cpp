#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[102][102];
int b[102][102];

int main()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (long long)a[i][j] + b[i][j] << ' ';
        }

        cout << '\n'; 
    }
}