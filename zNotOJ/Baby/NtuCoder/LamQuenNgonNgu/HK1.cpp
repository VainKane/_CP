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

    if (b == 0)
    {
        cout << "ERROR";
    }
    else
    {
        long long gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;

        if (b < 0)
        {
            b *= -1;
            a *= -1;
        }

        cout << a << ' ' << b;
    }
}