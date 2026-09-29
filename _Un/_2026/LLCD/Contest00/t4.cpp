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

int const N = 1009;
int const oo = 1e9 + 9;

int n;
int a[N][N];

ii dp[N][N];

int Count(int x, int k)
{
    if (!x) return 0;

    int res = 0;
    while (x % k == 0) x /= k, res++;
    return res;
}

bool cmp(ii a, ii b)
{
    int va = min(a.F, a.S), vb = min(b.F, b.S);
    if (va != vb) return va < vb;
    return a.F + a.S < b.F + b.S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, n) dp[0][i] = dp[i][0] = {oo, oo};
    dp[1][1] = {Count(a[1][1], 2), Count(a[1][1], 5)};

    FOR(i, 1, n) FOR(j, 1, n) if (i != 1 || j != 1)
    {
        int c2 = Count(a[i][j], 2), c5 = Count(a[i][j], 5);
        ii p1 = {dp[i - 1][j].F + c2, dp[i - 1][j].S + c5};
        ii p2 = {dp[i][j - 1].F + c2, dp[i][j - 1].S + c5};

        dp[i][j] = min(p1, p2, cmp);
    }

    // FOR(i, 1, n) FOR(j, 1, n) cout << min(dp[i][j].F, dp[i][j].S) << " \n"[j == n];
    cout << min(dp[n][n].F, dp[n][n].S);

    return 0;
}