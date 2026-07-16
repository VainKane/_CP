#include <bits/stdc++.h>

using namespace std;

struct Matrix
{
    int x[4][4];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

long long n;
int M;

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                res.x[i][j] = (res.x[i][j] + 1ll * a.x[i][k] * b.x[k][j]) % M;
            }
        }
    }

    return res;
}

Matrix PowMod(Matrix a, long long b)
{
    Matrix res;
    for (int i = 1; i <= 3; i++) res.x[i][i] = 1;
    
    while (b)
    {
        if (b & 1)
        {
            res = Multi(res, a);
        }

        b >>= 1;
        a = Multi(a, a);
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> M;

    Matrix t;
    t.x[1][1] = t.x[1][2] = t.x[1][3] = t.x[2][1] = t.x[3][2] = 1;

    Matrix u;
    u.x[1][1] = 4;
    u.x[2][1] = 2;
    u.x[3][1] = 1;

    int f[3] = {0, 1, 2};

    if (n <= 2)
    {
        cout << f[n];
        exit(0);
    }

    t = PowMod(t, n - 3);
    Matrix res = Multi(t, u);

    cout << res.x[1][1];

    return 0;
}