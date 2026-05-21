#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1 << (i))
#define BIT(i, x) (((x) >> (i)) & 1)

int const N = 25;
int n, k;

int a[N][N];
int dp[MK(20) + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    REP(i, n) REP(j, n) cin >> a[i][j];

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    REP(mask, MK(n))
    {
        for (int tmp = mask ^ (MK(n) - 1); tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            for (int haha = mask ^ (MK(n) - 1); haha; haha ^= haha & -haha)
            {
                int j = __builtin_ctz(haha & -haha);
                if (i == j) continue;
                dp[mask | MK(i)] = min(dp[mask | MK(i)], dp[mask] + a[i][j]);
            }
        }
    }

    int res = 1e9;
    REP(mask, MK(n)) if (__builtin_popcount(mask) == n - k) res = min(res, dp[mask]);

    cout << res;

    return 0;
}