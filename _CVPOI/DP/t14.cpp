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

long long a, b;
long long dp[20][2][10][10][2][2];

long long Get(long long x)
{
    vector<int> digits;

    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }

    reverse(all(digits));
    int n = sz(digits);

    memset(dp, 0, sizeof dp);
    dp[0][0][0][0][1][1] = 1;

    REP(i, n) REP(r, 2) FOR(cur, 0, 9) FOR(pre, 0, 9) REP(lead, 2) REP(preLead, 2)
    {
        long long &val = dp[i][r][cur][pre][lead][preLead];
        if (!val) continue;

        int lim = r ? 9 : digits[i];
        FOR(d, 0, lim) 
        {
            if (!lead && d == cur) continue;
            if (!preLead && d == pre) continue;
            dp[i + 1][r | (d < lim)][d][cur][lead & !d][lead] += val;
        }
    }

    long long res = 0;

    REP(r, 2) FOR(cur, 0, 9) FOR(pre, 0, 9) REP(lead, 2) REP(nLead, 2)
        res += dp[n][r][cur][pre][lead][nLead];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    cout << Get(b) - Get(a - 1);

    return 0;
}