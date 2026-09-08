#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;
int f[(int)1e5 + 10];

long long fMod(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 3;

    if (f[n] == 0)
    {
        f[n] = (fMod(n - 1) % mod + ( (2 * fMod(n - 2)) % mod ) ) % mod;
    }

    return f[n];
}

int n;

int main()
{
    cin >> n;

//    cout << fMod(n);

    f[1] = 1;
    f[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        f[i] = ( f[i - 1] % mod + (2 * f[i - 2]) % mod ) % mod;
    }

    cout << f[n];

    return 0;
}
