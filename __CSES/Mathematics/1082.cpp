#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

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

int inv2 = PowMod(2, MOD - 2);

int GetSum(long long l, long long r)
{
    if (l > r) return 0;

    int a = (l + r) % MOD;
    int b = (r - l + 1) % MOD;
    return (1ll * a * b % MOD * inv2) % MOD; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    int res = 0;

    for (long long i = 1; i <= n; i++)  
    {
        long long val = n / i;
        long long maxIdx = n / val;

        val %= MOD;
        res = (res + GetSum(i, maxIdx) * val) % MOD;
        i = maxIdx;
    }

    cout << res;

    return 0;
}