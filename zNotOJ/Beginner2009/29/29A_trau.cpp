#include <bits/stdc++.h>

using namespace std;

#define name "29A"

int const N = 1e5 + 5;

int n;
int a[N];

long long f[N];
long long g[N];
long long res = 0;

int GetSum(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = g[i] = GetSum(a[i]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] <= a[j]) continue;
            f[i] = max(f[i], f[j] + GetSum(a[i]));
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] <= a[j]) continue;
            g[i] = max(g[i], g[j] + GetSum(a[i]));
        } 

        // cout << i << ' ' << f[i] << ' ' << g[i] << '\n';
        res = max(res, f[i] + g[i] - GetSum(a[i]));
    }

    cout << res;

    return 0;
}