#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 55;
int const MOD = 1e9 + 7;

struct Matrix
{
    vector<vector<int>> x;
    int n;

    Matrix(int _n = 0)
    {
        n = _n;
        x.resize(n + 1, vector<int> (n + 1));
    }

    static Matrix I(int sz)
    {
        Matrix res(sz);
        FOR(i, 1, sz) res.x[i][i] = 1;
        return res;
    }

    Matrix operator * (Matrix const other) const
    {
        Matrix res(n);
        FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n)
            res.x[i][j] = (res.x[i][j] + 1ll * x[i][k] * other.x[k][j]) % MOD;
        return res;  
    }
};

int n;
long long k;

int a[N][N];

Matrix PowMod(Matrix a, long long b)
{
    Matrix res = Matrix::I(a.n);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    Matrix T(n), B(n);
    FOR(i, 1, n) FOR(j, 1, n) if (a[i][j])
    {
        T.x[i][j] = 1;
        B.x[i][1]++;
    }

    T = PowMod(T, k - 1) * B;
    
    int res = 0;
    FOR(i, 1, n) Add(res, T.x[i][1]);
    cout << res;

    return 0;
}