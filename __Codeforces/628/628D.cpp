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

int m, D;
string a, b;

int pw[N];
int dp[N][2][N][2][2];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int Cal(string &x)
{
    vector<int> digit;
    int n = sz(x);
    
    memset(dp, 0, sizeof dp);
    dp[0][0][0][1][1] = 1;

    REP(i, n) REP(r, 2) REP(s, m) REP(lead, 2) REP(even, 2) if (dp[i][r][s][lead][even])
    {
        int lim = r ? 9 : x[i] - '0';
        int newEven = lead ? 0 : (even ^ 1);
        int &x = dp[i][r][s][lead][even];

        if (newEven) 
        {
            if (lim >= D) Add(dp[i + 1][r | (D < lim)][(s + 1LL * D * pw[n - i - 1]) % m][lead & !D][newEven], x);
        }
        else FOR(d, 0, lim) if (d != D) Add(dp[i + 1][r | (d < lim)][(s + 1LL * d * pw[n - i - 1]) % m][lead & !d][newEven], x);
    }

    int res = 0;
    REP(r, 2) REP(lead, 2) REP(even, 2) Add(res, dp[n][r][0][lead][even]);
    return res;
}

bool Check(string &x)
{
    int sum = 0;
    int n = sz(x);
    
    REP(i, n) sum = (sum + 1LL * (x[i] - '0') * pw[n - i - 1]) % m;

    REP(i, n)
    {
        if (i & 1)
        {
            if (x[i] - '0' != D) return false;
        }
        else if (x[i] - '0' == D) return false;
    }

    return sum == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> D;
    cin >> a >> b;

    pw[0] = 1;
    FOR(i, 1, 2000) pw[i] = 1LL * pw[i - 1] * 10 % m;

    cout << (Cal(b) - Cal(a) + Check(a) + MOD) % MOD;

    return 0;
}