#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e3 + 5;
int const MOD = 1e9 + 7;

int t, k;
string l, r;

string x;

int dp[N][N][3];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int F(int i, int smaller, int last, int cnt)
{
    if (i == x.size())

    int &memo = dp[i][last][cnt];
    if (smaller && memo != -1) return memo;
    
    int lim = smaller ? 9 : x[i] - '0';
    int res = 0;

    FOR(d, 0, lim) 
    {
        int newLast = last;
        int newCnt = cnt;

        if (d == 4 || d == 7)
        {
            newCnt = min(2, cnt + (i + 1 - last <= k || !last));
            newLast = i + 1;
        }

        Add(res, F(i + 1, smaller | (d < lim), newLast, newCnt));
    }

    if (smaller) return memo = res;
    return res;
}

int Get(string s)
{
    x = s;
    return F(0, 0, 0, 0);
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

    memset(dp, -1, sizeof dp);

    cin >> t >> k;
    while (t--)
    {
        cin >> l >> r;

    }

    return 0;
}