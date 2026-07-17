#include <bits/stdc++.h>

using namespace std;

int const MOD = 2021;
int const M = 20; 

long long n;
int k;

struct Matrix
{
    int x[M + 2][M + 2];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }

    static Matrix I()
    {
        Matrix res;
        for (int i = 1; i <= k; i++) res.x[i][i] = 1;
        return res;
    }
};

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int k1 = 1; k1 <= k; k1++)
            {
                res.x[i][j] = (res.x[i][j] + 1ll * a.x[i][k1] * b.x[k1][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix Pow(Matrix a, long long b)
{
    Matrix res = Matrix::I();

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

Matrix Build(long long start, long long end)
{
    Matrix res = Matrix::I();

    for (long long i = end; i >= start; i--)
    {
        Matrix t;
        for (int j = 1; j <= k; j++)
        {
            t.x[j][j] = (t.x[j][j] + 2 * j) % MOD;
            t.x[j][j - 1] = (t.x[j][j - 1] + max(0ll, i - 2 * j + 2)) % MOD; 
        }

        res = Multi(res, t);
    }

    return res;
}

void Print(Matrix a)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
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

    cin >> n >> k;

    Matrix b;
    b.x[1][1] = 1;

    Matrix t1 = Build(((n - 100 + 1) / MOD) * MOD + 100, n);
    Matrix t2 = Build(100, min(100ll + MOD - 1, n - 1));
    Matrix t3 = Build(2, min(99ll, n));

    t2 = Pow(t2, (n - 100 + 1) / MOD);

    Matrix res = Multi(t1, t2);
    res = Multi(res, t3);
    res = Multi(res, b);

    // res = Multi(res, b); the code will still be true if this line is opened??
    
    // Print(t2);

    cout << res.x[k][1];

    return 0;
}