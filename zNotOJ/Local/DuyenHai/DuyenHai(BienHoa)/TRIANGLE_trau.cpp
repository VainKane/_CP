#include <bits/stdc++.h>

using namespace std;

#define name "TRIANGLE"

int const N = 2009;

int n;
int m;
int k;

int a[N][N];
long long p[N][N];

long long res = -1e18;

long long GetSum(int i, int l, int r)
{
    return p[i][r] - p[i][l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = p[i][j - 1] + a[i][j];
        }
    }
    
    for (int i = 1; i <= m - k + 1; i++)
    {
        for (int j = 1; j <= n - k + 1; j++)
        {
            long long s = 0;
            for (int u = 1; u <= k; u++)
            {
                s += GetSum(i + u - 1, j, j + u - 1);
            }
            // cout << i << ' ' << j << ' ' << s << '\n';
            res = max(res, s);
        }
    }

    cout << res;

    return 0;
}