#include <bits/stdc++.h>

using namespace std;

int Count(long long n)
{
    int count = 0;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count += 1;

            if (i != sqrt(n))
            {
                count += 1;
            }
        }
    }

    return count;
}

long long n;

int main()
{
    cin >> n;

    cout << Count(n);
}