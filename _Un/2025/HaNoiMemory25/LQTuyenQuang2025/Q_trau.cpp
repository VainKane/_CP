#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, c;
int a[N], w[N];

long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    FOR(i, 1, n) cin >> a[i] >> w[i];

    FOR(i, 1, n) REP(j, i) if (a[i] > a[j]) maxi(dp[i], dp[j] + a[i] - c * (w[i] != w[j] && j));
    cout << *max_element(dp + 1, dp + n + 1);

    // FOR(i, 1, n) cout << dp[i] << ' ';

    return 0;
}