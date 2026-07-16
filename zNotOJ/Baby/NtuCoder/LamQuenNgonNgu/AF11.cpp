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

int n;

long long sum = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;

        sum += Sum(value);
    }

    cout << sum;
}