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
#define name "ADN"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
long long const oo = 1e18;

int n;
string s, t = "ATGX";

int id[N], pos[N];
int cnt = 0;

long long dp[N][4];

void EZCases()
{
    bool haha = true;
    FOR(i, 1, n) if (s[i] != '?') haha = false;
    
    if (haha)
    {
        cout << 0;
        exit(0);
    }

    char hehe;
    FOR(i, 1, n) if (s[i] != '?')
    {
        hehe = s[i];
        break;
    }

    for (int i = 1; i <= n && s[i] == '?'; i++) s[i] = hehe;

    FORD(i, n, 1) if (s[i] != '?')
    {
        hehe = s[i];
        break;
    }

    for (int i = n; i >= 1 && s[i] == '?'; i--) s[i] = hehe;
}

void Init()
{
    cnt = 0;

    FOR(i, 1, n)
    {
        if (s[i] != s[i - 1]) cnt++;

        id[i] = cnt;
        pos[id[i]] = i;
    }

    FOR(i, 1, n) if (s[i] == '?')
    {
        if (s[pos[id[i] - 1]] == s[pos[id[i] + 1]]) s[i] = s[pos[id[i] - 1]];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;

    n = sz(s);
    s = " " + s;

    EZCases();
    Init();
    Init();

    FOR(i, 1, cnt) REP(c1, 4)
    {
        int idx = pos[i];
        dp[i][c1] = oo;

        FORD(j, i - 1, 0)
        {
            if (s[pos[j + 1]] != t[c1] && s[pos[j + 1]] != '?') break;
            REP(c2, 4) if (c1 != c2) mini(dp[i][c1], dp[j][c2] + 1LL * pos[j] * (idx - pos[j]));
        }
    }

    long long res = oo;
    REP(c, 4) mini(res, dp[cnt][c]);
    cout << res;

    return 0;
}