#include <bits/stdc++.h>

using namespace std;

int n;

long long value;
long long res;

int main()
{
    cin >> n;

    cin >> res;

    for (int i = 1; i < n; i++)
    {
        cin >> value;

        if (value < res)
        {
            res = value;
        }
    }

    cout << res;
}