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

int const N = 109;
int const M = 1e5 + 5;

int n, x;
int h[N], s[N], k[N];

long long dp[N][M];
long long f[N][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, n) cin >> k[i];

    FOR(i, 1, n) REP(rem, h[i])
    {
        deque<int> dq;

        for (int j = rem; j <= x; j += h[i])
        {
            while (!dq.empty() && (j - dq.front()) / h[i] > k[i]) dq.pop_front();            

            dp[i][j] = dp[i - 1][j];
            if (!dq.empty()) maxi(dp[i][j], f[i - 1][dq.front()] + (j - rem) / h[i] * s[i]);

            f[i - 1][j] = dp[i - 1][j] - (j - rem) / h[i] * s[i];
            while (!dq.empty() && f[i - 1][j] >= f[i - 1][dq.back()]) dq.pop_back();
            dq.push_back(j);
        }
    }

    cout << dp[n][x];

    return 0;
}