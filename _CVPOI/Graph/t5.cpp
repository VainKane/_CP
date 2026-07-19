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

int const N = 3e5 + 5;

int n, m, k;

int a[N];
vector<int> adj[N];

long long dp[N][MK(5) + 5]; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> a[i], a[i]--;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(u, 1, n) dp[u][MK(a[u])] = 1;
    REP(mask, MK(k)) FOR(u, 1, n) for (auto &v : adj[u]) if (!BIT(a[v], mask)) dp[v][mask | MK(a[v])] += dp[u][mask];

    long long res = 0;
    FOR(u, 1, n) REP(mask, MK(k)) if (__builtin_popcount(mask) > 1) res += dp[u][mask];
    cout << res;

    return 0;
}