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

int const N = 409;

int n, m;
string s, t;

int dp[N][N];
int last[26], nxt[N][26];

bool Check(int len)
{
    string t1 = " ", t2 = " ";

    FOR(i, 1, m)
    {
        if (i <= len) t1 += t[i];
        else t2 += t[i];
    }
    
    FOR(i, 0, len) memset(dp[i], 0x3f, (m + 1) * sizeof(int));
    dp[1][0] = nxt[0][t1[1] - 'a'];
    if (sz(t2) > 1) dp[0][1] = nxt[0][t2[1] - 'a'];

    FOR(i, 0, len) FOR(j, 0, m - len)
    {
        if (i && dp[i - 1][j] < n) mini(dp[i][j], nxt[dp[i - 1][j]][t1[i] - 'a']);
        if (j && dp[i][j - 1] < n) mini(dp[i][j], nxt[dp[i][j - 1]][t2[j] - 'a']);
    }

    return dp[len][m - len] <= n;
}

bool Solve()
{
    FOR(len, 1, m) if (Check(len)) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ts; cin >> ts;
    while (ts--)
    {
        cin >> s >> t;

        n = sz(s), m = sz(t);
        s = " " + s;
        t = " " + t;

        memset(last, 0x3f, sizeof last);
        FORD(i, n, 0)
        {
            REP(j, 26) nxt[i][j] = last[j];
            last[s[i] - 'a'] = i;
        }

        cout << (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}