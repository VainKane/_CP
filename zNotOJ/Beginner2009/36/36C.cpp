#include <bits/stdc++.h>

using namespace std;

int const N = 75;

int n, k;
long long f[N][N];
int a[N];

void Init()
{
    for (int i = 1; i <= n; i++) f[k][i] = 1;

    for (int i = k - 1; i >= 1; i--)
    {
        for (int x = 1; x <= n; x++)
        {
            for (int z = x + 1; z <= n; z++)
            {
                f[i][x] += f[i + 1][z];
            }
        }
    }
}

void Query1()
{
    long long res = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int x = a[i - 1] + 1; x < a[i]; x++)
        {
            res += f[i][x];
        }
    }

    cout << res << '\n';
}

void Query2(long long t)
{
    int x = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = x + 1; j <= n; j++)
        {
            if (t > f[i][j]) t -= f[i][j];
            else
            {
                cout << j << ' ';
                x = j;
                break;
            }
        }
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    Init();

    long long s = 0;
    for (int i = 1; i <= n - k + 1; i++)
    {
        s += f[1][i];
    }

    cout << s << '\n';

    int type;
    while (cin >> type)
    {
        if (type == 1) 
        {
            for (int i = 1; i <= k; i++) cin >> a[i];
            Query1();
        }
        else
        {
            long long t;
            cin >> t;
            Query2(t);
        }
    }

    return 0;
}