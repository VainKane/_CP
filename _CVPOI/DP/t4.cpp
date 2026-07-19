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

int n, k;

long long dp[12][96][MK(9) + 5];

vector<int> valid;
vector<int> adj[MK(9) + 5];

bool Check(int mask1, int mask2)
{
    if (mask1 & (mask2 << 1)) return false;
    if (mask1 & (mask2 >> 1)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    REP(mask, MK(n)) if (Check(mask, mask)) valid.push_back(mask);
    for (auto &mask1 : valid) for (auto &mask2 : valid) 
        if ((mask1 & mask2) == 0 && Check(mask1, mask2)) adj[mask1].push_back(mask2);
    
    dp[0][0][0] = 1;
    REP(i, n) FOR(cnt, 0, k) for (auto &mask : valid) if (dp[i][cnt][mask])
        for (auto &nxt : adj[mask]) dp[i + 1][cnt + __builtin_popcount(nxt)][nxt] += dp[i][cnt][mask];

    long long res = 0;
    for (auto &mask : valid) res += dp[n][k][mask];
    cout << res;

    return 0;
}