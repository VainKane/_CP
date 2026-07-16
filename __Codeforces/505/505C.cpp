#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 3e4 + 5;
int const oo = 3e4;

int n, d;

int a[N];
int dp[N][600];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n)
    {
        int p; cin >> p;
        a[p]++;
    }

    int os = max(d - 245, 1);

    memset(dp, -1, sizeof dp);
    dp[d][d - os] = a[d];
    int res = 0;


    FOR(i, d, oo) FOR(j, os, min(d + 245, oo)) if (dp[i][j - os] != -1)
    {
        maxi(res, dp[i][j - os]);
        FOR(k, max(j - 1, 1), min(j + 1, oo - i))
            maxi(dp[i + k][k - os], dp[i][j - os] + a[i + k]);
    }
    
    cout << res;

    return 0;
}