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

int const N = 1e5 + 5;
int MOD;

int n;
vector<int> adj[N];

int dp[N], f[N];
int pre[N], suf[N];

void DFSPrepare(int u, int p)
{
    dp[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        dp[u] = 1LL * dp[u] * (dp[v] + 1) % MOD;
    }
}

void DFS(int u, int p)
{
    vector<int> child = {0};
    for (auto &v : adj[u]) if (v != p) child.push_back(v);

    int m = sz(child) - 1;
    suf[m + 1] = 1;

    FOR(i, 1, m) pre[i] = 1LL * pre[i - 1] * (dp[child[i]] + 1) % MOD;
    FORD(i, m, 1) suf[i] = 1LL * suf[i + 1] * (dp[child[i]] + 1) % MOD;

    FOR(i, 1, m) f[child[i]] = (1LL * pre[i - 1] * suf[i + 1] % MOD * f[u] + 1) % MOD;
    FOR(i, 1, m) DFS(child[i], u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> MOD;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    pre[0] = f[1] = 1;
    DFS(1, -1);

    FOR(u, 1, n) cout << 1LL * dp[u] * f[u] % MOD << '\n';

    return 0;
}