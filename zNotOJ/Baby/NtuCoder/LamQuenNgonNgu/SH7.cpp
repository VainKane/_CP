#include <bits/stdc++.h>

using namespace std;

bool Check(long long n)
{
    if (n <= 1)
    {
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long n;

long long nextFibo;
long long f0 = 1;
long long f1 = 1;

long long res;

int main()
{
    cin >> n;

    while (true)
    {
        nextFibo = f0 + f1;
        f0 = f1;

        if (nextFibo > n)
        {
            break;
        }

        f1 = nextFibo;

        if (Check(f1))
        {
            res = f1;
        }
    }

    cout << res;

    return 0;
}