#include <bits/stdc++.h>

using namespace std;

int Count(long long n)
{
    int count = 0;

    while (n % 5 == 0)
    {
        count += 1;
        n /= 5;
    }

    return count;
}

long long n;

int main()
{
    cin >> n;

    cout << Count(n);
}