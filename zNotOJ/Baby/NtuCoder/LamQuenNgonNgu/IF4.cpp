#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;
long long c;
long long d;

int main()
{
    cin >> a >> b >> c >> d;

    long long max = a;

    if (max < b)
    {
        max = b;
    }
    if (max < c)
    {
        max = c;
    }
    if (max < d)
    {
        max = d;
    }

    cout << max;
}