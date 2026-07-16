#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define name "PIANO"

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, k;
int a[N];

int p[N], inv[N];

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (1ll * res * a) % MOD;
        b >>= 1;
        a = (1ll * a * a) % MOD;
    }

    return res;
}

int GetC(int k, int n)
{
    int res = (1ll * p[n] * inv[n - k]) % MOD;
    res = (1ll * res * inv[k]) % MOD;
    return res;
}

void Init()
{
    p[0] = 1;
    FOR(i, 1, n) p[i] = (1ll * p[i - 1] * i) % MOD;

    inv[n] = PowMod(p[n], MOD - 2);
    FORD(i, n - 1, 0) inv[i] = (1ll * (i + 1) * inv[i + 1]) % MOD;

    sort(a + 1, a + n + 1, greater<int> ());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    Init();

    int res = 0;
    FOR(i, 1, n - k + 1)
        res = (res + 1ll * a[i] * GetC(k - 1, n - i)) % MOD;

    cout << res;

    return 0;
}