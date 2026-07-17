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

int const N = 12;

long long l, r;
long long dp[N][2][2][2][N][N][2][2];

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
    dp[0][0][0][0][0][0][0][1] = 1;

    REP(i, n) REP(r, 2) REP(c4, 2) REP(c8, 2) FOR(digit, 0, 9) FOR(cnt, 0, n) REP(ok, 2) REP(lead, 2)
    {
        long long &x = dp[i][r][c4][c8][digit][cnt][ok][lead];
        if (c4 & c8) continue;
        if (x == 0) continue;

        int lim = r ? 9 : digits[i];
        FOR(d, 0, lim)
        {
            bool nR = r | (d < lim);
            int nCnt = (d == digit && !lead) ? cnt + 1 : 1;
            bool nOk = ok | (nCnt == 3);
            bool nLead = lead & (d == 0);

            dp[i + 1][nR][c4 | (d == 4)][c8 | (d == 8)][d][nCnt][nOk][nLead] += x;
        }
    }

    long long res = 0;
    REP(r, 2) REP(c4, 2) REP(c8, 2) if (!(c4 & c8)) FOR(digit, 0, 9) FOR(cnt, 0, n) REP(lead, 2)
        res += dp[n][r][c4][c8][digit][cnt][true][lead];
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> l >> r;
    cout << Get(r) - Get(l - 1);

    return 0;
}