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

int const N = 309;

int m, n;
char a[N][N];
int d[N][N];

string res = "";

string Get(string s, int i, int j)
{
    if (a[i][j] == '(' || a[i][j] == ')') s += a[i][j];
   return s;
}

void Try(int x, int y, int k, string s = "")
{
    if (y < 1 || y > n || k < 0) return;
    if (a[x][y] == '*')
    {
        if (k) return;
        if (sz(s) > sz(res)) res = s;
        else if (sz(s) == sz(res)) mini(res, s);
        return;
    }

    Try(x - 1, y, k + d[x - 1][y], Get(s, x - 1, y));
    Try(x - 1, y - 1, k + d[x - 1][y - 1], Get(s, x - 1, y - 1));
    Try(x - 1, y + 1, k + d[x - 1][y + 1], Get(s, x - 1, y + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, '*', sizeof a);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        if (a[i][j] == '(') d[i][j] = 1;
        if (a[i][j] == ')') d[i][j] = -1;
    }

    FOR(j, 1, n) if (a[m][j] == 'M') Try(m, j, 0);
    
    cout << sz(res) << '\n' << res;

    return 0;
}