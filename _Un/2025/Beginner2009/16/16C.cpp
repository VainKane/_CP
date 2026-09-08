#include <bits/stdc++.h>

using namespace std;

int const N = 509;
int const maxLog = 9;

int n;
int m;
int q;

long long a[N][N];
int lg[N];

long long st[N][N][maxLog];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            st[i][j][0] = a[i][j];
        }
    }

    lg[1] = 0;
    for (int i = 2; i <= 500; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int p = 1; (1 << p) <= n; p++)
        {
            for (int j = 1; j + (1 << p) - 1 <= n; j++)
            {
                st[i][j][p] = min(st[i][j][p - 1], st[i][j + (1 << (p - 1))][p - 1]);
            }
        }
    }

    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long res = LLONG_MAX;

        for (int i = x1; i <= x2; i++)
        {
            int k = lg[y2 - y1 + 1];
            res = min({res, st[i][y1][k], st[i][y2 - (1 << k) + 1][k]});
        }

        cout << res << '\n';
    }

    return 0;
}