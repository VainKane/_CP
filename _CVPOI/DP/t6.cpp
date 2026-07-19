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

int const N = 1009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int m, n;
int dp[N][MK(10) + 5];

vector<int> adj[MK(10) + 5];

bool Check(int mask1, int mask2)
{
    if (mask1 & mask2) return false;

    int tmp = (~mask1 & ~mask2) & (MK(n) - 1);
    if (tmp % 3) return false;
    tmp /= 3;
    if (tmp & (tmp << 1)) return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    swap(m, n);

    REP(mask1, MK(n)) REP(mask2, MK(n)) if (Check(mask1, mask2)) adj[mask1].push_back(mask2);

    dp[0][0] = 1;
    REP(i, m) REP(mask, MK(n)) for (auto &nxt : adj[mask]) Add(dp[i + 1][nxt], dp[i][mask]);
    cout << dp[m][0];

    return 0;
}