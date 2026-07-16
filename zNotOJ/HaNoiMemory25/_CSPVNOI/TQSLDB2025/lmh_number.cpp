#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 3009;

int n, m;
string s1, s2;

pair<int, char> dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    n = sz(s1); m = sz(s2);
    s1 = " " + s1;
    s2 = " " + s2;

    FORD(i, n, 1) FORD(j, m, 1)
    {
        if (s1[i] == s2[j]) dp[i][j] = {dp[i + 1][j + 1].F + 1, s1[i]};
        else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }

    pair<int, char> tmp;
    FOR(i, 1, n) FOR(j, 1, m) if (dp[i][j].S != '0') maxi(tmp, dp[i][j]);

    if (tmp.S == 0) cout << 0;

    int i = 1;
    int j = 1;
    while (tmp.F)
    {
        cout << tmp.S;
        while (s1[i] != tmp.S) i++;
        while (s2[j] != tmp.S) j++;
        tmp = dp[++i][++j];
    }

    return 0;
}