#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e3 + 5;
int const MOD = 1e9 + 7;

int t, k;
string l, r;

int dp[N][2][N][3];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int Get(string x)
{
    int n = x.size();

    FOR(i, 1, n) memset(dp[i], 0, sizeof dp[i]);
    dp[0][0][0][0] = 1;

    REP(i, n) FOR(r, 0, 1) FOR(last, 0, i) FOR(cnt, 0, 2) if (dp[i][r][last][cnt])
    {
        int lim = (r ? 9 : x[i] - '0');
        FOR(d, 0, lim) 
        {
            int newLast = last;
            int newCnt = cnt;

            if (d == 4 || d == 7)
            {
                newCnt = min(2, cnt + (i + 1 - last <= k || !last));
                newLast = i + 1;
            }

            Add(dp[i + 1][r | (d < lim)][newLast][newCnt], dp[i][r][last][cnt]);
        }
    }

    int res = 0;
    FOR(r, 0, 1) FOR(last, 0, n) Add(res, dp[n][r][last][2]);

    return res;
}

bool Check(string x)
{
    int last = -1e9;
    REP(i, x.size())
    {
        if (x[i] == '4' || x[i] == '7')
        {
            if (i - last <= k) return true;
            last = i;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t >> k;
    while (t--)
    {
        cin >> l >> r;
        
        int res = 0;
        Add(res, Get(r) + Check(l));
        Sub(res, Get(l));
        
        cout << res << '\n';
    }

    return 0;
}