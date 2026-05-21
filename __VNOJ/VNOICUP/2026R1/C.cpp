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

int const N = 509;

int n, k, s;
long long pre[N];

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        FOR(i, 1, n)
        {
            int x; cin >> x;
            pre[i] = pre[i - 1] + x;
        }

        memset(dp, -0x3f, sizeof dp);
        dp[0][0] = 0;

        FOR(i, 1, n) FOR(j, 1, min(k, i)) REP(p, i)
            maxi(dp[i][j], dp[p][j - 1] + (pre[i] - pre[p] <= s));


        cout << *max_element(dp[n] + 1, dp[n] + k + 1) << '\n';
    }

    return 0;
}