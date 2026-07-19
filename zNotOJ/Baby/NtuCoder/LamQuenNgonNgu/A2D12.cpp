#include <bits/stdc++.h>

using namespace std;

int n;

int a[102][102];
int b[102][102];

long long value = 0;

int m;
int p;

int main()
{
    cin >> m >> n >> p;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {        
                value += (long long)a[i][k] * b[k][j]; 
            }

            cout << value << ' ';
            value = 0;
        }

        cout << '\n';
    }
}