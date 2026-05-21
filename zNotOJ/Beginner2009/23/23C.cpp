#include <bits/stdc++.h>

using namespace std;

int const MOD = 666013;
int const H = 109;

int n;
int h;
int k;

struct Matrix
{
    int x[H][H];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            for (int k = 0; k <= h; k++)
            {
                res.x[i][j] = (res.x[i][j] + 1ll * a.x[i][k] * b.x[k][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix Pow(Matrix a, int b)
{
    Matrix res;
    for (int i = 0; i <= h; i++) res.x[i][i] = 1;
    
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

    cin >> n >> h >> k;

    Matrix t;

    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            if (abs(i - j) <= k)
            {
                t.x[i][j] = 1;
            }
        }
    }

    Matrix b;
    b.x[0][0] = 1;

    t = Pow(t, n - 1);
    t = Multi(t, b);

    cout << t.x[h][0];

    return 0;
}