#include <bits/stdc++.h>

using namespace std;

int SumMod(int n, int mod)
{
    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += ( (long long)(i % mod) * (i % mod) * (long long)(i % mod) ) % mod;
    }
    return sum % mod;
}

int n;

int main()
{
    cin >> n;

    cout << SumMod(n, 1000000007);
}