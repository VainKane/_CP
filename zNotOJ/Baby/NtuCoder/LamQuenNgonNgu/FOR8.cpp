#include <bits/stdc++.h>

using namespace std;

int u(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return 3 * u(n - 1) - u(n - 2);
    }
}


int n;

const long long d = 1e9 + 7;

long long u1 = 1;
long long u2 = 1;

long long next1 = 1;


int main()
{
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        // cout << "i " << i << '\n';
        // cout << "u2 " << u2 << '\n';
        // cout << "u1 " << u1 << '\n';

        // cout << "-----------------\n";

        next1 = 3 * u2 - u1;

        next1 %= d;

        u1 = u2 % d;
        u2 = next1;

    }

    cout << next1;
}