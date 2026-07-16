#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const N = 1e5 + 5;
int const M = 105;

struct Matrix
{
    int x[M][M];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

int n;
long long k;

int d[N];
int maxD = 0;

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= maxD + 1; i++)
    {
        for (int j = 1; j <= maxD + 1; j++)
        {
            for (int k = 1; k <= maxD + 1; k++)
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
    for (int i = 1; i <= maxD + 1; i++) res.x[i][i] = 1;

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
    for (int i = 1; i <= maxD + 1; i++)
    {
        for (int j = 1; j <= maxD + 1; j++)
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

    // freopen("23E.inp", "r", stdin);
    // freopen("23E.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        cin >> d[i];
        maxD = max(maxD, d[i]);
    }

    Matrix t;
    for (int i = 1; i < maxD; i++)
    {
        t.x[i][i + 1] += 1;
    }

    for (int i = 1; i <= n; i++)
    {
        t.x[maxD][maxD + 1 - d[i]] += 1;
    }

    for (int j = 1; j <= maxD + 1; j++) t.x[maxD + 1][j] += t.x[1][j];
    t.x[maxD + 1][maxD + 1] += 1;

    // Print(t);
    t = Pow(t, k);

    Matrix b;

    b.x[1][1] = 1;
    for (int i = 1; i < maxD; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= d[j])
            {
                b.x[i + 1][1] = (b.x[i + 1][1] + b.x[i - d[j] + 1][1]) % MOD;
            }
        }
    }

    b.x[maxD + 1][1] = 1;

    t = Multi(t, b);

    // Print(b);

    cout << t.x[maxD + 1][1];

    return 0;
}