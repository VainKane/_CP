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

int const N = 5009;
int const oo = 1e9;

int n;

int a[N];
vector<int> adj[N];

int dp[N][N];
int f[2][N];
int sz[N];

void DFS(int u, int p)
{
    dp[u][1] = a[u];
    sz[u] = 1;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        
        FORD(k1, sz[u], 0) FOR(k2, 0, sz[v])
            maxi(dp[u][k1 + k2], dp[u][k1] + dp[v][k2]);

        sz[u] += sz[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, -0x3f, sizeof dp);
    DFS(1, -1);

    FOR(k, 1, n)
    {
        int res = -oo;
        FOR(u, 1, n) maxi(res, dp[u][k]);
        cout << res << '\n';
    }

    return 0;
}