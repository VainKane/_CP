#include <bits/stdc++.h>

using namespace std;

int const mod = 10000;

int PowMod(int a, long long b)
{
    int res = 1;

    while (b)
    {
        if (b & 1)
        {
            res *= a;
            res %= mod;
        }

        b >>= 1;
        a *= a;
        a %= mod;
    }

    return res % mod;
}

int a;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> n;

    cout << PowMod(a, PowMod(2, n - 1));

    return 0;
}