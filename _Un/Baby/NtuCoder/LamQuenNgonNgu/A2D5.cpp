#include <bits/stdc++.h>

using namespace std;

int n;

long long value;
long long res = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        cin >> value;
        if (value % 2 == 0)
        {
            if (value > res)
            {
                res = value;
            }
        }
    }

    cout << res;
}