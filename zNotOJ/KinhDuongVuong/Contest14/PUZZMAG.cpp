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
#define name "PUZZMAG"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 55;
int const M = 1e4 + 5;
int const MOD = 1e9 + 7;

int n, m;

int a[N];
int dp[N][M];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int Solve()
{
    FOR(i, 1, n) memset(dp[i], 0, 4 * (m + 1));
    FOR(j, 1, m) dp[1][j] = 1;

    FOR(i, 2, n) FOR(j, 1, m)
    {
        dp[i][j] = dp[i][j - 1];
        int p = j - a[i];
        if (p >= 1) Add(dp[i][j], dp[i - 1][p]);
    }

    return dp[n][m];
}

namespace Sub1
{
    bool CheckSub()
    {
        FOR(i, 2, n) if (a[i] != a[i - 1]) return false;
        return true;
    }

    void Process()
    {
        int res = 1;
        FOR(i, 1, n) res = 1LL * res * i % MOD;
        cout << 1LL * res * Solve() % MOD;
    }
}

int main()
{
    //freopen(name".inp", "r", stdin);
    //freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;

    return 0;
}
