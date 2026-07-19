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

int const N = 509;
int MOD;

int n, m;

int cnt[N];

int dp[2][N][N];
int cur = 0, nxt = 1;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int Comb(int x)
{
    if (x <= 1) return 0;
    return x * (x - 1) / 2 % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> MOD;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        char ch; cin >> ch;
        cnt[j] += (ch == '1');
    }

    int cnt0 = 0, cnt1 = 0;
    FOR(i, 1, n)
    {
        cnt0 += cnt[i] == 0;
        cnt1 += cnt[i] == 1;
    }

    dp[cur][cnt0][cnt1] = 1;

    FOR(i, m, n - 1)
    {
        FOR(c0, 0, n)
        {
            int c1 = 2 * n - 2 * c0 - 2 * i;

            if (c0 >= 2) Add(dp[nxt][c0 - 2][c1 + 2], 1LL * dp[cur][c0][c1] * Comb(c0) % MOD);
            if (c1 >= 2) Add(dp[nxt][c0][c1 - 2], 1LL * dp[cur][c0][c1] * Comb(c1) % MOD);
            if (c0 >= 1) Add(dp[nxt][c0 - 1][c1], 1LL * dp[cur][c0][c1] * c0 * c1 % MOD);
        }

        swap(cur, nxt);
        memset(dp[nxt], 0, sizeof dp[nxt]);
    }

    cout << dp[cur][0][0];

    return 0;
}