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

int const N = 1e5 + 5;
int const K = 12;

int n, k;
int a[N];

int pre[N];
ll preI[N];

ll dp[N][K];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FORD(i, n, 1) cin >> a[i];

    FOR(i, 1, n)
    {
        pre[i] = pre[i - 1] + a[i];
        preI[i] = preI[i - 1] + 1LL * (n - i) * a[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    FOR(j, 1, k) FOR(i, 1, n) REP(p, i)
        mini(dp[i][j], dp[p][j - 1] + preI[i] - preI[p] - 1LL * (n - i) * (pre[i] - pre[p]));

    cout << dp[n][k];

    return 0;
}