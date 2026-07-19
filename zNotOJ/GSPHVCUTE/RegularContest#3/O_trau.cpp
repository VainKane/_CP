#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define name "bracket"

template <class X, class Y>
    bool maxi(X &x, Y &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

template <class X, class Y>
    bool mini(X &x, Y &y)
    {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }

int const N = 2009;
int const MOD = 1e9 + 19972207;

int n, m;

int closeId[N];
int openId[N];

int maxCloseId[N][N];
int minOpenId[N][N];

int dp[N][N];

void PrintZero()
{
    cout << 0;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;

        if ((y - x + 1) & 1) PrintZero();
        if (closeId[x] && y != closeId[x]) PrintZero();
        if (openId[y] && x != openId[y]) PrintZero();
        if (openId[x] || openId[y]) PrintZero();

        closeId[x] = y;
        openId[y] = x;
    }

    FOR(l, 1, n) 
    {
        maxCloseId[l][l] = closeId[l];
        minOpenId[l][l] = openId[l] ? openId[l] : n + 1;

        FOR(r, l + 1, n)
        {
            maxCloseId[l][r] = maxCloseId[l][r - 1];
            minOpenId[l][r] = minOpenId[l][r - 1];

            if (closeId[r]) maxi(maxCloseId[l][r], closeId[r]);
            if (openId[r]) mini(minOpenId[l][r], openId[r]);
        }
    }

    FORD(l, n, 1) for (int r = l + 1; r <= n; r += 2)
    {
        if (maxCloseId[l][r] > r || minOpenId[l][r] < l)
        {
            dp[l][r] = 0;
            continue;
        }

        #define DP(l, r) ((l) > (r) ? 1 : dp[l][r])

        if (closeId[l]) 
        {
            int &p = closeId[l];
            dp[l][r] = (dp[l][r] + 1ll * DP(l + 1, p - 1) * DP(p + 1, r)) % MOD;
        }
        else for (int p = l + 1; p <= r; p += 2) 
            dp[l][r] = (dp[l][r] + 1ll * DP(l + 1, p - 1) * DP(p + 1, r)) % MOD;
    }

    cout << dp[1][n];

    return 0;
}