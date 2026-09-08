#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second
#define name "robot"

int const N = 89;
int const K = 2002;
int const OS = 82;

int t;
int n, k;
string s;

bool dp[N][K][2][2 * N];

void Solve()
{
    FOR(i, 1, n) FOR(o, 0, k) memset(dp[i][o], false, sizeof dp[i][o]);

    dp[0][0][0][OS] = true;
    REP(i, n) FOR(o, 0, min(i, k)) REP(d, 2) FOR(pos, -i, i)
    {
        if (!dp[i][o][d][pos + OS]) continue;

        dp[i + 1][o + (s[i] == 'D')][d][pos + OS + (d ? -1 : 1)] = true;
        dp[i + 1][o + (s[i] == 'M')][!d][pos + OS] = true;
    }

    int res = 0;

    for (int o = k & 1; o <= k; o += 2) 
    REP(d, 2) FOR(pos, -n, n) if (dp[n][o][d][pos + OS]) res = max(res, abs(pos));

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        Solve();
    }

    return 0;
}