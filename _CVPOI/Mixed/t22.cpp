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

int const N = 67;
int const MOD = 998244353;

int n;
int a[N], pre[N];
int dp[N];

int Get(ll x)
{
    FOR(i, 1, n)
    {
        if (BIT(i - 1, x)) dp[i] = (pre[i - 1] + 1LL * dp[i - 1] * a[i]) % MOD;
        else dp[i] = dp[i - 1];
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    dp[0] = pre[0] = 1;
    FOR(i, 1, n) pre[i] = 1LL * pre[i - 1] * (a[i] + 1) % MOD;

    int q; cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (Get(r) - Get(l - 1) + MOD) % MOD << '\n';
    }

    return 0;
}