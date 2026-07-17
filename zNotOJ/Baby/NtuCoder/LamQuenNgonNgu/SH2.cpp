#include <bits/stdc++.h>

using namespace std;

bool Check(long long n)
{
    if (n <= 1)
    {
        return false;
    }

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long n;

int main()
{
    cin >> n;

    if (Check(n))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}