#include <bits/stdc++.h>

using namespace std;

int x[100];

int n;

void printRes()
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i];
    }
    cout << '\n';
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n - 1)
        {
            printRes();
        }
        else
        {
            Try(i + 1);
        }
    }
}



int main()
{
    cin >> n;

    Try(0);
    
}