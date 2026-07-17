#include <bits/stdc++.h>

using namespace std;

int Sum(long long n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int GCD(int a, int b)
{
    if (a * b == 0)
    {
        return a + b;
    }
    else if (a % b == 0)
    {
        return b;
    }
    else
    {
        return GCD(b, a % b);
    }
}


long long a;
long long b;

int main()
{
    cin >> a >> b;

    a = Sum(abs(a));
    b = Sum(abs(b));

    cout << a * b / GCD(a, b);
}