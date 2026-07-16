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

int const N = 2009;

int n, x;

int a[N];
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
    sz[u] = 1;

    memset(f[cur], -0x3f, sizeof f[cur]);
    f[cur][0] = 0;

    FOR(i, 1, sz(child))
    {
        cur ^= 1;
        memset(f[cur], -0x3f, sizeof f[cur]);

        int v = child[i - 1];
        REP(k1, sz[u]) REP(k2, sz[v])
        {
            maxi(f[cur][k1 + k2], f[cur ^ 1][k1] + dp[v][k2]);
            if (dp[v][k2] >= 0) maxi(f[cur][k1 + k2 + 1], f[cur ^ 1][k1]);
        }

        sz[u] += sz[v];
    }

    REP(k, sz[u]) maxi(dp[u][k], f[cur][k] + a[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;

    FOR(i, 1, n)
    {
        int val; cin >> val;
        a[i] = x - val;
    }

    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, -0x3f, sizeof dp);
    DFS(1, -1);

    FORD(k, n - 1, 0) if (dp[1][k] >= 0)
    {
        cout << n - k - 1;
        break;
    }

    return 0;
}