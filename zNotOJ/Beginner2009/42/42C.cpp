#include <bits/stdc++.h>

using namespace std;

int const N = 409;

int m, n, q;
long long bit[N][N];

void Update(int u, int v, int val)
{
    for (int i = u; i <= m; i += i & -i)
    {
        for (int j = v; j <= n; j += j & -j)
        {
            bit[i][j] += val;
        }
    }
}

long long Get(int u, int v)
{
    long long res = 0;

    for (int i = u; i > 0; i -= i & -i)
    {
        for (int j = v; j > 0; j -= j & -j)
        {
            res += bit[i][j];
        }
    }

    return res;
} 

long long Get(int u, int v, int x, int y)
{
    return Get(x, y) - Get(x, v - 1) - Get(u - 1, y) + Get(u - 1, v - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            Update(i, j, x);
        }
    }

    cin >> q;
    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int u, v, x;
            cin >> u >> v >> x;
            Update(u, v, x);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << Get(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}