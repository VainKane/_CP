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

int const NMATRIX = 100;
int const MOD = 1e9 + 7;

struct Matrix
{
    int x[102][102];

    Matrix()
    {
        memset(x, 0, sizeof x);
    };

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

int m, n;
int s[102], l[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) cin >> s[i];
    FOR(i, 1, m) cin >> l[i];

    Matrix T, B;

    B.x[1][1] = 1;
    FOR(i, 1, m) FOR(j, 1, m) T.x[i][j] = s[j] * (s[i] + l[i]) + l[j] * s[i];

    T = PowMod(T, n) * B;

    int res = 0;
    FOR(i, 1, m) Add(res, T.x[i][1]);
    cout << res;

    return 0;
}