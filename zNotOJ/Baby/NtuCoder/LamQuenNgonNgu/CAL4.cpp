#include <bits/stdc++.h>

using namespace std;

int n;
long long sum = 0;

int main()
{
    cin >> n;

    for (long long i = 1; i <= (2 * (long long)n + 1); i += 2)
    {
        sum += i;
    }

    cout << sum;
}