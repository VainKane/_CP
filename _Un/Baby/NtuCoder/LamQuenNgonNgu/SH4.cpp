#include <bits/stdc++.h>

using namespace std;

long long Sum(long long n)
{
    long long sum = 0;

    for (long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i != sqrt(n))
            {
                sum += n / i;
            }
        }
    }

    return sum;
}

long long n;

int main()
{
    cin >> n;

    cout << Sum(n);
}