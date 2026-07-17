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

int const N = 2009;
int const MOD = 1e9 + 7;

int m, n;
char a[N][N];

int cntR[N][N], cntC[N][N];
int posR[N], posC[N];

int dpR[N][N], dpD[N][N];
int sumD[N], sumR[N];

void Init()
{
    FORD(i, m, 1) FORD(j, n, 1)
    {
        cntR[i][j] = cntR[i][j + 1] + (a[i][j] == 'R');
        cntC[j][i] = cntC[j][i + 1] + (a[i][j] == 'R');
    }

    FOR(i, 1, max(m, n)) posR[i] = posC[i] = 1;

    if (m == 1 && n == 1)
    {
        cout << 1;
        exit(0);
    }
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();

    FOR(j, 1, n) sumR[j] = dpR[1][j] = (cntR[1][1] <= n - j);
    FOR(i, 1, m) sumD[i] = dpD[i][1] = (cntC[1][1] <= m - i);

    FOR(i, 2, m) FOR(j, 2, n)
    { 
        while (cntR[i][posR[i] + 1] > n - j && posR[i] < j) 
        {
            Sub(sumD[i], dpD[i][posR[i]]);
            posR[i]++;
        }
        while (cntC[j][posC[j] + 1] > m - i && posC[j] < i) 
        {
            Sub(sumR[j], dpR[posC[j]][j]);
            posC[j]++;
        }

        dpD[i][j] = sumR[j];
        dpR[i][j] = sumD[i];

        Add(sumD[i], dpD[i][j]);
        Add(sumR[j], dpR[i][j]);
    }

    cout << (dpR[m][n] + dpD[m][n]) % MOD;

    return 0;
}