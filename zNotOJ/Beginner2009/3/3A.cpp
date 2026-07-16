#include <bits/stdc++.h>

using namespace std;

long long MultiMod(long long a, long long b, long long mod)
{
    long long res = 0;

    while (b)
    {
        if (b & 1)
        {
            res = (res % mod) + (a % mod);
            res %= mod;
        }

        b >>= 1;
        a = (a % mod) + (a % mod);
        a %= mod;
    }

    return res;
}

long long a;
long long b;
long long c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;

    cout << MultiMod(a, b, c);

    return 0;
}