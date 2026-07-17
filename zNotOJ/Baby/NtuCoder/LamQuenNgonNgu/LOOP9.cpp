#include <bits/stdc++.h>

using namespace std;

long long n;

long long sum = 1;

int main()
{
    cin >> n;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == sqrt(n))
            {
                sum += i;
            }
            else
            {
                sum += i + (n / i);
            }
        }
    }

    if (sum == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}