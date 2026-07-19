#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const MOD = 1e9 + 7;

int n;
string s;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1ll * res * a % MOD;
        b >>= 1;
        a = 1ll * a * a % MOD;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    
    int res = PowMod(26, n);

    for (int m = s.size(); m <= n; m += s.size())
        res = (res - (1ll * PowMod(26, n - m) * (n - m + 1) % MOD) + MOD) % MOD;

    cout << res;

    return 0;
}