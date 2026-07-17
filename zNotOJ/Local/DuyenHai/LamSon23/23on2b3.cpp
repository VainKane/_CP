#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))
#define name "23on2b3"

int dp[35][2];

int Get(int x, int r)
{
    int k = 32 - __builtin_clz(r);
    if (k < 32 - __builtin_clz(x)) return 0;

    memset(dp, 0, sizeof dp);
    dp[k][0] = 1;

    FORD(i, k, 1) FOR(smaller, 0, 1) if (dp[i][smaller]) 
    {
        int lim = smaller ? 1 : BIT(i - 1, r);
        FOR(d, 0, lim) 
        {
            int newSmaller = smaller | (d < lim);

            if (BIT(i - 1, x) && d) dp[i - 1][newSmaller] += dp[i][smaller];
            else if (!BIT(i - 1, x)) dp[i - 1][newSmaller] += dp[i][smaller];
        }
    }

    return dp[0][0] + dp[0][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        // cout << Get(a, r) << " " << Get(a, l - 1) << '\n';
        cout << Get(a, r) - Get(a, l - 1) << '\n';
    
        // cout << Get(a, 1);
    }   

    return 0;
}