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

int const N = 22;

int n, m;
char s[N][N];
int a[N][N];

int c[N][N];
int sMask[N][N];

int dp[MK(20) + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, n) REP(j, m) cin >> s[i][j];
    REP(i, n) REP(j, m) cin >> a[i][j];

    REP(i, n) REP(j, m)
    {
        int ma = 0;
        REP(k, n) if (s[k][j] == s[i][j])
        {
            maxi(ma, a[i][j]);
            c[i][j] += a[k][j];
            sMask[i][j] |= MK(k);
        }

        c[i][j] -= ma;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    REP(mask, MK(n)) for (int tmp = mask ^ (MK(n) - 1); tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        REP(j, m)
        {
            mini(dp[mask | MK(i)], dp[mask] + a[i][j]);
            mini(dp[mask | sMask[i][j]], dp[mask] + c[i][j]);
        }
    }

    cout << dp[MK(n) - 1];

    return 0;
}