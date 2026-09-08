#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int n;

long long sum = 0;
long long num = 1;

int main()
{
    cin >> n;

    for (long long i = 1; i <= n; i++)
    {
        num *= i;
        num %= mod;
        num %= mod;

        sum += num;
        sum %= mod;
        sum %= mod;
    }

    cout << sum;
}