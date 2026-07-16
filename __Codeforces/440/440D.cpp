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

int const N = 409;
int const oo = 1e9;

int n, k;
vector<int> adj[N];

int dp[N][N];
int f[2][N];
int sz[N];

void DFS(int u, int p)
{
    vector<int> child;
    for (auto &v : adj[u]) if (v != p)
    {
        child.push_back(v);
        DFS(v, u);
    }

    bool cur = 1;
    memset(f[cur], 0x3f, sizeof f[cur]);
    f[cur][0] = 0;

    sz[u] = 1;

    REP(i, sz(child))
    {
        int v = child[i];

        cur ^= 1;
        memset(f[cur], 0x3f, sizeof f[cur]);

        REP(k1, sz[u]) REP(k2, sz[v])
        {
            mini(f[cur][k1 + k2], f[cur ^ 1][k1] + dp[v][k2]);
            mini(f[cur][k1], f[cur ^ 1][k1] + dp[v][k2] + 1);
        }

        sz[u] += sz[v];
    }

    FOR(k, 1, sz[u])
    {
        if (k) mini(dp[u][k], f[cur][k - 1]);
        mini(dp[u][1], f[cur][k] + 1);
    }

    dp[u][sz[u]] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = oo;

    FOR(u, 1, n)
    {
        memset(dp, 0x3f, sizeof dp);
        DFS(u, -1);

        mini(res, dp[u][k]);
    }

    cout << res;

    return 0;
}