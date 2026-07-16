#include <bits/stdc++.h>

using namespace std;

long long Pow(long long a, int b)
{
    long long res = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= (long long)a;
        }

        b /= 2;
        a *= a; 
    }

    return res;
}

int ChuKi(long long n)
{
    int chuKi = 1;
    int mu = 0;

    n /= 10;

    while (n > 0)
    {
        chuKi += Pow(10, mu) * (n % 10);
        mu++;
        n /= 10;
    }

    return chuKi;
}

int Count(long long n)
{   
    int count = 0;
    int chuki = ChuKi(n);


    if (chuki >= 2)
    {
        count += chuki * 2;

        if (n % 10 == 0)
        {
            count--;
        }
        else if (n % 10 < 5)
        {
            count -= 2;
        }
    }
    else if (chuki == 2)
    {
        if (n % 10 == 0)
        {
            count += 1;
        }
        else if (n % 10 >= 5)
        {
            count += 2;
        }

        n /= 10;

        if (n)
    }

    return count;
}

long long n;

int main()
{
    cin >> n;

    cout << Count(n);
}