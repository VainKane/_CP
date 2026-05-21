#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 30;
int const NMATRIX = 10;
int const MOD = 1e9 + 7;

struct Matrix
{
    int x[NMATRIX + 1][NMATRIX + 1];

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

    Matrix const operator * (Matrix const other) const
    {
        Matrix res;

        FOR(k, 1, NMATRIX) FOR(i, 1, NMATRIX) FOR(j, 1, NMATRIX)
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

int m, n;
int c[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;
        
        Matrix B, T;

        FOR(i, 1, m) cin >> B.x[i][1];
        FOR(i, 1, m) cin >> c[i];

        FOR(i, 1, m - 1) T.x[i][i + 1] = 1;
        FOR(i, 1, m) T.x[m][i] = c[m - i + 1];

        T = PowMod(T, n - 1) * B;
        cout << T.x[1][1] << '\n';
    }

    return 0;
}