#include <bits/stdc++.h>

using namespace std;

bool Check(long long n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; (long long)i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long n;
long long res;

int main()
{
    cin >> n;

    res = n;

    while (Check(res) == false)
    {
        res += 1;
    }

    cout << res;
}