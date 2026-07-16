#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2009;
int const oo = 1e9 + 1;

int m, n;
bool a[N][N];
bool b[N][N];

int dp[N][2][2];

bool Check(bool a[N][N], int i, int x, int y, int z)
{
    FOR(j, 1, n) 
    {
        int x0 = a[i][j] ^ x;
        int x1 = a[i - 1][j] ^ y;
        int x2 = a[i - 2][j] ^ z;

        if (x0 == x1 && x0 == x2) return false;
    } 

    return true;
}

int Solve(bool a[N][N])
{
    memset(dp, 0x3f, sizeof dp);
    REP(i, 2) REP(j, 2) dp[1][i][j] = dp[2][i][j] = i + j;
    
    FOR(i, 3, m) REP(x, 2) REP(y, 2) REP(z, 2) if (Check(a, i, x, y, z))
    {
        mini(dp[i][x][y], dp[i - 1][y][z] + x);
    }

    int res = oo;
    REP(i, 2) REP(j, 2) mini(res, dp[m][i][j]);

    // cout << res << ' ';

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;
        FOR(i, 1, m) FOR(j, 1, n)
        {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
            b[j][i] = a[i][j];
        }

        int res = Solve(a);   
        swap(m, n);
        res += Solve(b);

        if (res >= oo) res = -1;
        cout << res << '\n';
    }

    return 0;
}