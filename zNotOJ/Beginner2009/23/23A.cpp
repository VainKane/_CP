#include <bits/stdc++.h>

using namespace std;

struct Matrix
{
    int x[3][3];
    
    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int t;
long long n;

Matrix T;

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                res.x[i][j] = (res.x[i][j] + 1ll * a.x[i][k] * b.x[k][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix PowMod(Matrix a, long long b)
{
    Matrix res;
    for (int i = 1; i <= 2; i++) res.x[i][i] = 1;

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

    cin >> t;

    Matrix b;
    
    b.x[1][1] = 3;
    b.x[2][1] = 1;

    while (t--)
    {
        cin >> n;

        T.x[1][1] = 1; T.x[1][2] = 2;
        T.x[2][1] = 1; T.x[2][2] = 0;
        
        if (n == 1) 
        {
            cout << 1 << '\n';
            continue;
        }
        else if (n == 2)
        {
            cout << 3 << '\n';
            continue;
        }
        else if (n == 3)
        {
            cout << 5;
        }
        
        T = PowMod(T, n - 2);

        Matrix c = Multi(T, b);

        cout << c.x[1][1] << '\n';
    }

    return 0;
}