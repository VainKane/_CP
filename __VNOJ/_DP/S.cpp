#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e4 + 5;
int const MOD = 1e9 + 7;

string k;
int D;

int dp[N][2][109];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> D;

    dp[0][0][0] = 1;

    REP(i, k.size()) REP(sum, D) FOR(r, 0, 1)
    {
        int lim = r ? 9 : k[i] - '0';
        FOR(d, 0, lim) Add(dp[i + 1][r | (d < lim)][(sum + d) % D], dp[i][r][sum]); 
    }

    int res = (dp[k.size()][0][0] + dp[k.size()][1][0]) % MOD;
    Sub(res, 1);

    cout << res;

    return 0;
}