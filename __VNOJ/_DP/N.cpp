#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 409;
long long const oo = 1e18;

int n;

long long pre[N];
long long dp[N][N];

long long Get(int l, int r)
{
    if (l > r) return 0;
    return pre[r] - pre[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    FORD(i, n, 1) FOR(j, i + 1, n) 
    {
        dp[i][j] = oo;
        FOR(p, i, j - 1)
            mini(dp[i][j], dp[i][p] + Get(i, p) + dp[p + 1][j] + Get(p + 1, j));
    }

    cout << dp[1][n];

    return 0;
}