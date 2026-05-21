#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)
{
    if (a * b == 0)
    {
        return a + b;
    }

    long long r = a % b;

    if (r == 0)
    {
        return b;
    }

    while (r)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long a;
long long b;

int main()
{
    cin >> a >> b;

    a = abs(a);
    b = abs(b);

    long long gcd = GCD(a, b);

    cout << gcd << '\n';

    if (a == 0 && b == 0)
    {
        cout << 0;
    }
    else
    {
        if (a > b)
        {
            cout << (a / gcd) * b;
        }
        else
        {
            cout << (b / gcd) * a;
        }
    }
}