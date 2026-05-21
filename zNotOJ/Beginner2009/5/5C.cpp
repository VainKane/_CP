#include <bits/stdc++.h>

using namespace std;

long long f(long long n)
{
    if (n == 1) return 0;

    int i = 0;

    while (pow(2, i) < n) i++;

    long long k = pow(2, i - 1);

    if (n <= k)
    {
        return (k - 2 * k + n);
    }
    else
    {
        return ( f(k - 2 * k + n) + 1 ) % 3;
    }
}

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        cout << f(n) << '\n';
    }

    return 0;
}