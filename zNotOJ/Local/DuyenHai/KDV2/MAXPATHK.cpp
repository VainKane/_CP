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

int const N = 509;

int m, n, k;
int a[N][N];

long long dp[N][N][16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    memset(dp, -0x3f, sizeof dp);

    dp[1][1][0] = a[1][1];
    dp[1][1][1] = 0;

    FOR(i, 1, m) FOR(j, 1, n) FOR(cnt, 0, k)
    {
        maxi(dp[i + 1][j][cnt], dp[i][j][cnt] + a[i + 1][j]);
        maxi(dp[i][j + 1][cnt], dp[i][j][cnt] + a[i][j + 1]);

        maxi(dp[i + 1][j][cnt + 1], dp[i][j][cnt]);
        maxi(dp[i][j + 1][cnt + 1], dp[i][j][cnt]);
    }

    cout << *max_element(dp[m][n], dp[m][n] + k + 1);

    return 0;
}