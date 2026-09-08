#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU6"

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

    static Matrix I(int n)
    {
        Matrix res(n);
        FOR(i, 1, n) res.x[i][i] = 1;
        return res;
    }

    Matrix operator * (Matrix const other) const
    {
        Matrix res(n);
        
        FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n)
            res.x[i][j] = (res.x[i][j] + 1ll * x[i][k] * other.x[k][j]) % MOD;
        
        return res;
    }

    void Print()
    {
        cout << "Matrix:\n";
        FOR(i, 1, n) 
        {
            FOR(j, 1, n) cout << x[i][j] << ' ';
            cout << '\n';
        }
    }
};

int const N = 2009;

int n, k;
int dp[N][N];

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

void Sub2()
{
    dp[0][0] = 1;
    FOR(i, 1, n) 
    {
        FOR(j, 0, k) Add(dp[i][0], dp[i - 1][j]);
        FOR(j, 1, k) Add(dp[i][j], dp[i - 1][j - 1]);
    }

    int res = 0;
    FOR(j, 0, k) Add(res, dp[n][j]);
    cout << res;

    exit(0);
}

void Sub3()
{
    Matrix T(k + 1);
    FOR(j, 0, k) T.x[1][j + 1] = 1;
    FOR(j, 1, k) T.x[j + 1][j] = 1;

    Matrix B(k + 1);
    B.x[1][1] = 1;

    T = PowMod(T, n) * B;

    int res = 0;
    FOR(i, 0, k) Add(res, T.x[i + 1][1]);
    cout << res;

    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    k--;
    
    if (n <= 2000 && k <= 2000) Sub2();
    Sub3();

    return 0;
}