#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;
int const NMATRIX = 101;
int const MOD = 1e9 + 7;

struct Matrix
{
    int x[102][102];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }

    static Matrix I()
    {
        Matrix res;
        FOR(i, 1, NMATRIX) res.x[i][i] = 1;
        return res;
    }

    Matrix operator * (Matrix const other) const
    {
        Matrix res;

        FOR(i, 1, NMATRIX) FOR(j, 1, NMATRIX) FOR(k, 1, NMATRIX)
            res.x[i][j] = (res.x[i][j] + 1ll * x[i][k] * other.x[k][j]) % MOD;

        return res;
    }
};

Matrix PowMod(Matrix a, int b)
{
    Matrix res = Matrix::I();

    while (b)
    {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }

    return res;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, x;
int d[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    FOR(i, 1, n) cin >> d[i];

    Matrix T, B; 

    FOR(i, 2, 100) T.x[i - 1][i] = 1;
    FOR(i, 1, n) T.x[100][101 - d[i]]++;
    T.x[101][2] = T.x[101][101] = 1;

    B.x[1][1] = 1;
    FOR(i, 1, 99) FOR(j, 1, n) if (i >= d[j])
        Add(B.x[i + 1][1], B.x[i - d[j] + 1][1]);

    B.x[101][1] = B.x[1][1];

    T = PowMod(T, x) * B;
    cout << T.x[101][1];

    return 0;
}