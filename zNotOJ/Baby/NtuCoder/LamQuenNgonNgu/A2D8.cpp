#include <bits/stdc++.h>

using namespace std;

int n;

long long matrix[102][102];

long long sum = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    if (n == 1)
    {
        sum = matrix[0][0];
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            sum += (matrix[i][0] + matrix[i][n - 1]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            sum += (matrix[0][i] + matrix[n - 1][i]);
        }
    }

    cout << sum;
}