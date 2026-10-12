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

int const N = 2009;
ll const oo = 1e18;

int n, m;

int a[N], b[N];
int preA[N], preB[N];

ll dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i], preA[i] = preA[i - 1] + a[i];
    FOR(i, 1, m) cin >> b[i], preB[i] = preB[i - 1] + b[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    FOR(i, 1, n) REP(p, i)
    {
        int k = preA[i] - preA[p] - i + p;

        ll x = oo;
        FOR(j, 0, m)
        {
            mini(dp[i][j], 1LL * k * (preB[j] - j) + x);
            mini(x, 1LL * k * (j - preB[j]) + dp[p][j]);
        }
    }

    cout << dp[n][m];
    
    return 0;
}