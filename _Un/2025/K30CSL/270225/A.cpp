#include <bits/stdc++.h>

using namespace std;

int const M = 1e6 + 10;
int const mod = 1e9 + 7;

int n;
int q;

int l;
int r;

int a[M];

long long b[M];
long long p[M];

int mo = ((int)1e9 + 8) / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        long long x = 1ll * a[i] * a[i];
        x %= mod;
        x += b[i - 1];
        x %= mod;
        b[i] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        long long x = p[i - 1];
        x += a[i];
        x %= mod;
        p[i] = x;
    }

    while (q--)
    {
        cin >> l >> r;

        long long res = p[r] - p[l - 1];
        res %= mod;
        res *= p[r] - p[l - 1];
        res %= mod;
        res -= b[r] - b[l - 1];
        res += mod;
        res %= mod;
        res %= mod;
        res *= mo;
        res %= mod;
        
        cout << res << '\n';
    }

    return 0;
}