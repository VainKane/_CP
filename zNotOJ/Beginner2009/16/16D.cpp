#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (((x) >> (i)) & 1)

int const N = 1e5 + 10;
int const maxLog = 17;

int n;
int m;

int a[N];
int up[N][maxLog];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int u = 1; u <= n; u++)
    {
        up[u][0] = a[u];
        for (int k = 1; (1 << k) <= n; k++)
        {
            up[u][k] = up[up[u][k - 1]][k - 1];
        }
    }

    while (m--)
    {
        int v, k;
        cin >> v >> k;

        int u = v;
        for (int i = 0; i <= maxLog; i++)
        {
            if (bit(i, k))
            {
                u = up[u][i];
            }
        }

        cout << u << '\n';
    }

    return 0;
}