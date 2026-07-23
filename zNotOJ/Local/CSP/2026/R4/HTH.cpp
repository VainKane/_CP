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
#define name "HTH"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;
ll const oo = 1e18;

int n;
ll c, l, r;

int x[N], y[N];
ll pre[N];

ll dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> c >> l >> r;
    FOR(i, 1, n) cin >> x[i];
    FOR(i, 1, n) cin >> y[i], pre[i] = pre[i - 1] + y[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    FOR(i, 1, n) REP(j, i) if (dp[j] < oo)
    {
        ll sum = pre[i] - pre[j];
        if (sum < l || sum > r) continue;
        mini(dp[i], dp[j] + c + x[i] * (pre[i] - pre[j]));
    }

    cout << (dp[n] < oo ? dp[n] : -1);

    return 0;
}