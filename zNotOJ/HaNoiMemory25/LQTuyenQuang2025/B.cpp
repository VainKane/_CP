#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 5e5 + 5;
int oo = 0;

int m, n, c;
vector<vector<int>> a;
vector<vector<long long>> dp;
long long preM[N][2], preN[N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("B.inp", "r", stdin);

    cin >> m >> n >> c;

    a.assign(m + 5, vector<int> (n + 5, 0));
    dp.assign(m + 5, vector<long long> (n + 5, -1e18));

    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j], maxi(oo, a[i][j]);
    memset(preM, -0x3f, sizeof preM);
    memset(preN, -0x3f, sizeof preN);

    preM[1][0] = preN[1][0] = -a[1][1]; 
    preM[1][1] = preN[1][1] = a[1][1];
    dp[1][1] = 0;

    FOR(i, 1, m) FOR(j, 1, n) if (i != 1 || j != 1)
    {
        dp[i][j] = max({
            preM[i][0] + a[i][j] - c,
            preM[i][1] - a[i][j] - c,
            preN[j][0] + a[i][j] - c,
            preN[j][1] - a[i][j] - c
        });

        maxi(preM[i][0], dp[i][j] - a[i][j]);
        maxi(preM[i][1], dp[i][j] + a[i][j]);
        maxi(preN[j][0], dp[i][j] - a[i][j]);
        maxi(preN[j][1], dp[i][j] + a[i][j]);
    }

    cout << dp[m][n] << '\n';

    return 0;
}