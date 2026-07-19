#include <bits/stdc++.h>

using namespace std;

#define name "BAI01"

long long n;

long long Solve(long long x)
{
    long long res = 0;
    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res += i;
            if (i * i != x) res += x / i;
        }
    }
    return res;
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    cout << Solve(n);
}