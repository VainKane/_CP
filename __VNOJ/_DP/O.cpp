#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1 << (i))

int const N = 21;
int const MOD = 1e9 + 7;

int n;

bool a[N][N];
int dp[MK(N)];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

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
            int j = __builtin_ctz(tmp & -tmp);
            if (a[i][j]) Add(dp[mask | MK(j)], dp[mask]);
        }
    }

    cout << dp[MK(n) - 1];

    return 0;
}