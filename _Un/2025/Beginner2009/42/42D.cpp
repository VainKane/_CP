#include <bits/stdc++.h>

using namespace std;

int const N = 709;
int const MOD = 30103;

int n;
int a[N];

int f[N][N];
int bit[N][2009];

int res = 0;

void Update(int u, int v, int val)
{
    for (int i = u; i <= n; i += i & -i)
    {
        for (int j = v; j <= 2000; j += j & -j)
        {
            bit[i][j] = (bit[i][j] + val) % MOD;
        }
    }
}

int Get(int u, int v)
{
    int res = 0;

    for (int i = u; i; i -= i & -i)
    {
        for (int j = v; j; j -= j & -j)
        {
            res = (res + bit[i][j]) % MOD;
        }
    }

    return res;
}

int Get(int u, int v, int x, int y)
{
    return (Get(x, y) - Get(x, v - 1) - Get(u - 1, y) + Get(u - 1, v - 1) + 2 * MOD) % MOD;
}

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Init();

    for (int v = n; v; v--)
    {
        for (int u = 2; u < v; u++)
        {
            f[u][v] += Get(1, a[u] + a[v] + 1, u - 1, 2000);
        }
        for (int u = 1; u < v; u++)
        {
            Update(u, a[u] + a[v], f[u][v]);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            res = (res + f[u][v] - 1 + MOD) % MOD;
        }
    }

    cout << res;

    return 0;
}