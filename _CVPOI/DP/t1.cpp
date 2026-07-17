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

int const N = 36;

int n;
int a[N][N];

double dp[MK(20) + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];

    dp[0] = 1;
    REP(mask, MK(n)) 
    {
        int i = __builtin_popcount(mask);
        for (int tmp = mask ^ (MK(n) - 1); tmp; tmp ^= tmp & -tmp)
        {
            int j = __builtin_ctz(tmp);
            maxi(dp[mask | MK(j)], dp[mask] * a[i][j] * 0.01);
        }
    }

    cout << fixed << setprecision(6) << dp[MK(n) - 1] * 100;

    return 0;
}