#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;

int n;

int a[(int)1e5 + 10];
int b[(int)1e5 + 10];

int f[(int)1e5 + 10];
int g[(int)1e5 + 10];
int h[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++) cin >> b[i];

    f[1] = 1ll * a[1];
    g[1] = 1ll * b[1];

    for (int i = 2; i <= n; i++)
    {
        long long x = (1ll * f[i - 1] + g[i - 1] + h[i - 1]) % mod;
        x *= 1ll * a[i];
        x %= mod;
        
        long long y = (1ll * f[i - 1] + g[i - 1] + h[i - 1]) % mod;
        y *= 1ll * b[i];
        y %= mod;

        long long z = 1ll * b[i - 1] * f[i - 1];
        z %= mod;
        z += 1ll * (b[i - 1] - 1) * g[i - 1];
        z %= mod;
        z += 1ll * b[i - 1] * h[i - 1];
        z %= mod;

        f[i] = x;
        g[i] = y;
        h[i] = z;
    }

    cout << (1ll * f[n] + g[n] + h[n]) % mod;

    return 0;
}