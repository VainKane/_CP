#include <bits/stdc++.h>

using namespace std;

int n;
long long sum = 0;

int cows[100009];

bool cmp(int a, int b)
{
    if (a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }

    sort(cows, cows + n, cmp);

    for (int i = 0; i < n; i++)
    {
        if (cows[i] - i > 0)
        {
            sum += (long long)(cows[i] - i); 
        }
        else
        {
            break;
        }
    }

    cout << sum;
}
