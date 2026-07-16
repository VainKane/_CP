#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

int const N = 1009;

int n, m;

int a[N], b[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    FOR(i, 1, n) FOR(j, 1, m)
    {
        if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }

    vector<int> res;

    while (n && m)
    {
        if (a[n] == b[m]) 
        {
            res.push_back(a[n]);
            n--; m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1]) n--;
        else m--;
    }

    reverse(all(res));
    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << ' ';

    return 0;
}