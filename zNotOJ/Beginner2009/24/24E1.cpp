#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const N = 1e6 + 5;
int const M = 5;

long long n;

struct Matrix   
{
    int x[(1 << M) + 2][(1 << M) + 2];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 0; i < (1 << M); i++)
    {
        for (int j = 0; j < (1 << M); j++)
        {
            for (int k = 0; k < (1 << M); k++)
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
    for (int i = 0; i < (1 << M); i++) res.x[i][i] = 1;

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
    for (int i = 0; i < (1 << M); i++)
    {
        for (int j = 0; j < (1 << M); j++)
        {
            cout << a.x[i][j] << ' ';
        }

        cout << '\n';
    }
}

int flip(int i, int mask)
{
    return mask ^ (1 << i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    Matrix t;

    for (int mask = 0; mask < (1 << M); mask++)
    {
        t.x[mask][mask] += 5;
    }

    for (int mask = 0; mask < (1 << M); mask++)
    {
        for (int i = 0; i < M; i++)
        {
            t.x[mask][flip(i, mask)] += 1;
        } 
    }

    Matrix b;
    b.x[0][0] = 5;
    for (int i = 1; i < 5; i++) 
    {
        b.x[1 << i][0] = 1;
    }

    // Print(t);

    t = Pow(t, n - 1);
    t = Multi(t, b);

    cout << t.x[0][0];

    return 0;
}