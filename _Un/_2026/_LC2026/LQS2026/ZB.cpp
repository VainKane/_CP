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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 109;
int const M = 2009;
int const MOD = 998244353;
int const OS = 101;

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int n, m;
int a[N][M];

int s[N];
int dp[N][2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n)
    {
        ll tmp = 0;
        FOR(j, 1, m) cin >> a[i][j], tmp += a[i][j];
        s[i] = tmp % MOD;
    }

    int res = 1;
    FOR(i, 1, n) res = 1LL * res * (s[i] + 1) % MOD;
    Sub(res, 1);

    dp[0][OS] = 1;

    FOR(j, 1, m)
    {
        FOR(i, 1, n) FOR(x, -i, i)
        {
            int &val = dp[i][x + OS] = dp[i - 1][x + OS];
            val = (val + 1LL * a[i][j] * dp[i - 1][x + OS - 1]) % MOD;
            val = (val + 1LL * (s[i] - a[i][j] + MOD) * dp[i - 1][x + OS + 1]) % MOD;
        }

        FOR(x, 1, n) Sub(res, dp[n][x + OS]);
    }

    cout << res;

    return 0;
}