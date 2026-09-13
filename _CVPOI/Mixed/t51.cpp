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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 3e4 + 5;
int const lim = 3e4;

int n, d;
int a[N];

int dp[N][436];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        a[x]++;
    }

    int minLen = max(1, d - 250), maxLen = min(lim, d + 150);

    memset(dp, -1, sizeof dp);
    dp[d][d - minLen] = a[d];

    int res = 0;
    FOR(i, d, lim) FOR(j, minLen, maxLen) if (dp[i][j - minLen] != -1)
    {
        maxi(res, dp[i][j - minLen]);
        FOR(k, -1, 1) if (j + k - minLen >= 0 && i + j + k <= lim)
            maxi(dp[i + j + k][j + k - minLen], dp[i][j - minLen] + a[i + j + k]);
    }

    cout << res;

    return 0;
}