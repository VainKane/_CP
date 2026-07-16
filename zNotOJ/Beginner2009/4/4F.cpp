#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;

int PowMod(long long a, int b)
{
    long long res = 1;

    while (b)
    {
        if (b & 1)
        {
            res = (1LL * res * a ) % mod;
        }

        b >>= 1;
        a = (1LL * a * a) % mod;
    }

    return res;
}

int t;

int m;
int n;

int p[(int)2e7 + 10];
int md[(int)2e7 + 10];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    p[0] = 1; 

    for (int i = 1; i <= 2e7; i++)
    {
        long long x = (1LL * p[i - 1] * i);
        x %= mod;
        p[i] = x;
    }

    md[(int)2e7] = PowMod(p[(int)2e7], mod - 2);

    for (int i = 2e7 - 1; i >= 0; i--)
    {
        long long x = 1LL * md[i + 1] * (i + 1);
        x %= mod;
        md[i] = x;
    }

    cin >> t;

    while (t--)
    {
        res = 0;

        cin >> m >> n;

        for (int a = 0; a <= m; a++)
        {
            int c = m - a;
            int b = n - c;

            if (b >= 0)
            {
                long long ca = p[a + b + c];
                ca *= md[a];
                ca %= mod;
                ca *= md[b + c];
                ca %= mod;

                long long cb = p[b + c];
                cb *= md[b];
                cb %= mod;
                cb *= md[c];
                cb %= mod;

                res += ca * cb;
                res %= mod;
            }
        }

        cout << res << '\n';
    }

    return 0;
}