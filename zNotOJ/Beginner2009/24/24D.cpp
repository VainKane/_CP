#include <bits/stdc++.h>

using namespace std;

int const M = 3;
int const MOD = 1e9 + 7;

struct Matrix
{
    int x[M + 1][M + 1];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

long long n;

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                res.x[i][j] = (res.x[i][j] + 1ll * a.x[i][k] * b.x[k][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix Pow(Matrix a, long long b)
{
    Matrix res;
    for (int i = 1; i <= M; i++) res.x[i][i] = 1;

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

void Print(Matrix a)
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << a.x[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    Matrix t;
    t.x[1][2] = t.x[2][1] = t.x[2][2] = t.x[3][2] = t.x[3][3] = 1;

    Matrix b;
    b.x[1][1] = b.x[2][1] = b.x[3][1] = 1;

    t = Pow(t, n);
    t = Multi(t, b);

    // Print(t);
    cout << t.x[3][1];

    return 0;
}