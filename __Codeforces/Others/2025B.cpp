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
            res *= a;
            res %= mod;
        }

        b >>= 1;
        a *= a;
        a %= mod;
    }

    return res;
}

int Solve(int n, int k)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return PowMod(2LL, k);
    }        
}

int t;
int k;

int n[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        cout << Solve(n[i], k) << '\n';
    }

    return 0;
}
