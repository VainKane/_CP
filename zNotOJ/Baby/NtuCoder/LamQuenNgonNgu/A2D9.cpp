#include <bits/stdc++.h>

using namespace std;

int n;

long long matrix[102][102];

bool Check(long long matrix[102][102])
{
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            for (int j = 0; j <= i; j++)
            {
                if (matrix[n - j][i - j] != 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

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

    if (Check(matrix))
    {
        cout << "YES";
    }    
    else
    {
        cout << "NO";
    }

}