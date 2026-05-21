#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;

long long sum = 0;

int main()
{
    cin >> a >> b;

    for (long long i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            if (b % (3 * i) == 0)
            {
                sum += i;
            }

            if (i != sqrt(a))
            {
                long long u = a / i;

                if (b % (3 * u) == 0)
                {
                    sum += u;
                }
            }
        }
    }

    cout << sum;

    return 0;
}