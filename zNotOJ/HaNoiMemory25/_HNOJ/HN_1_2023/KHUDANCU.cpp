#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 5;
int const NN = 1e5 + 5;

int m, n;
int d, k;

#define name "KHUDANCU"

char a[N][NN];
int b1[N][NN];
int b2[N][NN];
int p1[N][NN];
int p2[N][NN];

void Init()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'M')
            {
                
            }
        }
    }

    for (int i = m; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            p1[i][j] = p1[i + 1][j] + p1[i][j + 1] - p1[i + 1][j + 1] + b1[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p2[i][j] = p2[i - 1][j] + p2[i][j - 1] - p2[i - 1][j - 1] + b2[i][j];
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
            if (a[i][j] == 'P' && p1[i][j] >= k && p2[i][j] >= k)
            {
                cout << 1;
                res++;
            }
            else cout << 0;
        }
        cout << '\n';
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

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

    return 0;
}