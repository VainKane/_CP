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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 209;

int n, k;
char s[N];

ll dp[N][N][N][2];
int id[256];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> s[i];

    id['('] = 0, id['['] = 1, id['{'] = 2;
    id[')'] = 3, id[']'] = 4, id['}'] = 5;

    FOR(i, 1, n) dp[i + 1][i][0][0] = 1;

    FORD(l, n, 1) for (int r = l + 1; r <= n; r += 2) FOR(c, 1, k) REP(p, 2)
    {
        if (p)
        {
            int delta = 0;
            if (s[l] == '?' && s[r] == '?') delta = 3;
            else if ((s[l] == '?' && id[s[r]] > 2) || (id[s[l]] < 3 && s[r] == '?')) delta = 1;
            else if (id[s[r]] - id[s[l]] == 3) delta = 1;
            
            dp[l][r][c][p] = delta * (dp[l + 1][r - 1][c - 1][0] + dp[l + 1][r - 1][c - 1][1]);
        }
        else for (int i = l + 1; i <= r - 2; i += 2)
        {
            FOR(c1, 1, k) dp[l][r][c][p] += dp[l][i][c][1] * (dp[i + 1][r][c1][0] + dp[i + 1][r][c][1]);
            FOR(c2, 1, k) dp[l][r][c][p] += dp[l][i][c][1] * (dp[i + 1][r][c][0] + dp[i + 1][r][c2][1]);
        }
    }

    cout << dp[1][n][k][0] + dp[1][n][k][1];

    return 0;
}