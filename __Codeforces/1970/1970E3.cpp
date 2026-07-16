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

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

struct Matrix
{
    vector<vector<int>> x;
    int m, n;

    Matrix(int _m = 0, int _n = 0)
    {
        m = _m;
        n = _n;
        x.assign(m + 5, vector<int>(n + 5, 0));
    }

    static Matrix I(int n)
    {
        Matrix res(n, n);
        FOR(i, 1, n) res.x[i][i] = 1;
        return res;
    }

    Matrix operator * (Matrix const other) const
    {
        Matrix res(m, other.n);

        FOR(i, 1, m) FOR(j, 1, other.n) FOR(k, 1, n)
            res.x[i][j] = (res.x[i][j] + 1LL * x[i][k] * other.x[k][j]) % MOD;

        return res;
    }

    void Print()
    {
        FOR(i, 1, m)
        {
            FOR(j, 1, n) cout << x[i][j] << ' ';
            cout << '\n';
        }
    }
};

Matrix PowMod(Matrix a, int b)
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

int m, n;
int s[N], l[N], t[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n;
    FOR(i, 1, m) cin >> s[i];
    FOR(i, 1, m) cin >> l[i];
    FOR(i, 1, m) t[i] = s[i] + l[i];

    Matrix C(m, 2);
    Matrix D(2, m);
    Matrix B(m, 1);

    FOR(i, 1, m)
    {
        C.x[i][1] = t[i];
        C.x[i][2] = l[i];
        D.x[1][i] = t[i];
        D.x[2][i] = -l[i] + MOD;
    }

    B.x[1][1] = 1;
    Matrix A = C * (PowMod(D * C, n - 1) * (D * B));

    int res = 0;
    FOR(i, 1, m) Add(res, A.x[i][1]);
    cout << res;

    return 0;
}