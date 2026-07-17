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

int const N = 1009;
int const oo = 1e9;

int n;
int u[N], v[N], w[N];

int a[N][MK(3) + 5];
int dp[N][2][2];

void Minz(int i, int r, int x)
{
    mini(dp[i][r][x & 1], x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 2, n) cin >> u[i];
        FOR(i, 2, n) cin >> v[i];
        FOR(i, 1, n) cin >> w[i];

        FOR(i, 1, n) REP(mask, MK(3))
            a[i][mask] = u[i] * BIT(0, mask) + v[i] * BIT(1, mask) + w[i] * BIT(2, mask);

        memset(dp, 0x3f, sizeof dp);
        dp[0][0][0] = 0;
        
        REP(i, n) REP(r, 2) REP(par, 2)
        {
            int &cur = dp[i][r][par];
            if (!r)
            {
                Minz(i + 1, 0, cur + u[i + 1] + v[i + 1]);
                Minz(i + 1, 1, cur + u[i + 1] + v[i + 1] + w[i + 1]);
            }
            else REP(mask, MK(3))
            {
                int cnt = __builtin_popcount(mask);
                if (cnt == 1 && !BIT(2, mask)) Minz(i + 1, 0, cur + a[i + 1][mask]);
                else if (cnt > 1) Minz(i + 1, 1, cur + a[i + 1][mask]);
            }
        }

        int res = dp[n][1][0];
        if (res > oo) res = -1;

        cout << res << '\n';
    }

    return 0;
}