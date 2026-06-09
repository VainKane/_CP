#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
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

int const NMat = 3;
int const MOD = 1e9 + 7;

struct Matrix
{
    int x[NMat][NMat];
    int n;

    Matrix(int _n = 0)
    {
        n = _n;
        memset(x, 0, sizeof x);
    }

    Matrix operator * (Matrix const other) const
    {
        Matrix res = Matrix(n);

        FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n)
            res.x[i][j] = (res.x[i][j] + 1LL * x[i][k] * other.x[k][j]) % MOD;

        return res;
    }

    void Print()
    {
        FOR(i, 1, n)
        {
            FOR(j, 1, n) cout << x[i][j] << ' ';
            cout << '\n';
        }
    }
};

Matrix I(int n)
{
    Matrix res(n);
    FOR(i, 1, n) res.x[i][i] = 1;
    return res;
}

Matrix PowMat(Matrix a, long long b)
{
    Matrix res = I(2);

    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    Matrix t, b;
    t = b = Matrix(2);

    t.x[1][2] = t.x[2][1] = t.x[2][2] = b.x[2][1] = 1;
    cout << (PowMat(t, n) * b).x[1][1];

    return 0;
}