#include <bits/stdc++.h>

using namespace std;

#define name "KHUDANCU"

int const N = 1e3 + 5;
int const NN = 1e5 + 5;

int n, m;
int k, d;

char a[N][NN];
int b[N][NN];

void Init()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'M')
            {
                for (int u = max(1, i - d); u <= min(m, i + d); u++)
                {
                    for (int v = max(1, j - d); v <= min(n, j + d); v++)
                    {
                        b[u][v]++;
                    }
                }
            }
        }
    }
}

void Solve()
{
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'P') res += (b[i][j] >= k);
        }
    }
    cout << res;
    cerr << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> m >> n >> d >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    Init();
    Solve();

    // for (int i = 1; i <= m; i++) 
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << b[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}