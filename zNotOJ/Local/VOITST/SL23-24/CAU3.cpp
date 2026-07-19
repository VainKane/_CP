#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU3"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, k, x;

int a[N];
int pw[11];
long long dp[N][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k >> x;
    FOR(i, 1, n) cin >> a[i];

    pw[0] = 1;
    FOR(i, 1, k) pw[i] = pw[i - 1] * x;

    FOR(i, 1, n) FOR(j, 0, k) FOR(p, 0, j)
        maxi(dp[i][j], dp[i - 1][j - p] | (1ll * a[i] * pw[p]));

    cout << *max_element(dp[n], dp[n] + k + 1);

    return 0;
}