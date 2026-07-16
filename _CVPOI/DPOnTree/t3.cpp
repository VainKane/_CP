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
long long const oo = 1e18;

int n, m;

int a[N];
vector<pair<int, int>> adj[N];
bool mark[N];

long long dp[N], dpPar[N];
int cnt[N];

long long res = oo;

void DFSPrepare(int u, int p)
{
    cnt[u] = mark[u];
    dp[u] = 0;

    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;
        if (v == p) continue;

        DFSPrepare(v, u);
        cnt[u] += cnt[v];

        if (cnt[v]) dp[u] += dp[v] + 2 * w + a[u];
    }
}

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        if (m - cnt[v]) dpPar[v] = dpPar[u] + dp[u] + 2 * w + a[v];
        if (cnt[v]) dpPar[v] -= dp[v] + 2 * w + a[u];
        DFS(v, u);
    }

    long long tmp = dp[u] + dpPar[u];
    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v != p && cnt[v]) tmp -= a[u];
    }

    if (m - cnt[u]) tmp -= a[u];
    mini(res, tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int u; cin >> u;
        mark[u] = true;
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    cout << res;

    return 0;
}