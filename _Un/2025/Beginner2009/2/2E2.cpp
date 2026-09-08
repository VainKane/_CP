#include <bits/stdc++.h>

using namespace std;

int PowMod(long long a, int b)
{
    long long res = 1;

    while (b)
    {
        if (b & 1)
        {
            res = (res % 29) * (a % 29);
            res %= 29;
        }

        b >>= 1;
        a = (a % 29) * (a % 29);
        a %= 29;
    }

    return res;
}

int x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> x)
    {
        if (x == 0)
        {
            return 0;
        }

        int p1 = (PowMod(2, 2 * x + 1) - 1);
        p1 %= 29;

        int p2 = (PowMod(3, x + 1) - 1) * PowMod(2, 27);
        p2 %= 29;

        int p3 = (PowMod(167, x + 1) - 1) * PowMod(166, 27);
        p3 %= 29;
        
        cout << (p1 * p2 * p3) % 29 << '\n';
    }

    return 0;
}