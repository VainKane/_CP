#include <bits/stdc++.h>

using namespace std;

int PowMod(long long a, int b, int mod)
{
    long long res = 1;

    while (b)
    {
        if (b & 1)
        {
            res = (res % mod) * (a % mod);
            res %= mod;
        }

        b >>= 1;
        a = (a % mod) * (a % mod);
        a %= mod;
    }

    return res;
}

int a;
int b;
int m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> m;

    cout << PowMod(1LL * a, b, m);

    return 0;
}