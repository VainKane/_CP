#include <bits/stdc++.h>

using namespace std;

int const N = 35;

int n;
int a[2 * N];

long long f[2 * N][N];

void Query1()
{
    long long res = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        int x = a[i - 1];
        if (x > 0 && a[i] > x) res += f[i][x -1];
    }

    cout << res << '\n';
}

void Query2(long long k)
{
    cout << "0 ";

    int x = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (x > 0 && k <= f[i][x - 1])
        {
            cout << --x << ' ';
        }
        else
        {
            if (x > 0) k -= f[i][x - 1];
            cout << ++x << ' ';
        }
    }   

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    f[2 * n][0] = 1;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        f[i][0] = f[i + 1][1];
        for (int x = 1; x <= n; x++)
        {
            f[i][x] = f[i + 1][x + 1] + f[i + 1][x - 1];
        }
    }

    cout << f[0][0] << '\n';

    int type;
    while (cin >> type)
    {
        if (type == 1)
        {
            for (int i = 0; i <= 2 * n; i++) cin >> a[i];
            Query1();
        }
        else
        {
            long long k;
            cin >> k;
            Query2(k);
        }
    }

    // cout << "\ndebug: " << f[1][1];
    
    return 0;
}