#include <bits/stdc++.h>

using namespace std;

int PowMod(long long a, long long b)
{
    long long res = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= (long long)(a % 10);
            res %= 10;
        }

        a *= (long long)(a % 10);
        a %= 10;
        b /= 2;
    }

    return res % 10;
}

long long a;
long long b;

int main()
{
    cin >> a >> b;

    cout << PowMod(a, b);
}