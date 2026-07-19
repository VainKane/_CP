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

int const N = 1e6 + 5;

int n;
int a, b, c;
int x[N], pre[N];

long long dp[N];

long long Val(int l, int r)
{
    long long s = pre[r] - pre[l - 1];
    return a * s * s + b * s + c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b >> c;
    FOR(i, 1, n) cin >> x[i], pre[i] = pre[i - 1] + x[i];

    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;

    FOR(i, 1, n) REP(j, i) maxi(dp[i], dp[j] + Val(j + 1, i));
    // cout << dp[n];

    FOR(i, 1, n) cout << dp[i] << ' ';


    return 0;
}