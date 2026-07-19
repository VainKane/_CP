#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define sz(v) ((int)v.size())

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 109;

int n;
string s;
int dp[2][N][N * N];
int cur = 0, nxt = 1;

int cnt0 = 0;

void Init()
{
    n = sz(s);
    s = " " + s;

    FOR(i, 1, n) cnt0 += s[i] == '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    Init();
    
    dp[cur][0][0] = s[1] == '0';
    dp[cur][1][0] = s[1] == '1';

    FOR(i, 1, n - 1) 
    {
        memset(dp[nxt], 0x3f, sizeof dp[nxt]);
        FOR(c0, 0, min(i, cnt0)) FOR(c01, 0, c0 * (i - c0))
        {
            mini(dp[nxt][c0 + 1][c01], dp[cur][c0][c01] + (s[i + 1] == '1'));
            mini(dp[nxt][c0][c01 + c0], dp[cur][c0][c01] + (s[i + 1] == '0'));
        }
        swap(cur, nxt);
    }

    cout << (dp[cur][cnt0][cnt0 * (n - cnt0) / 2] + 1) / 2;

    return 0;
}