#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2009;
int const oo = 2000;
int const MOD = 1e9 + 7;

int n, d;
int a[N];
vector<int> adj[N];

int dp[N];

void DFS(int u, int p, int &id)
{
    dp[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        if (a[v] > d + a[id] || a[v] < a[id]) continue;
        if (a[v] == a[id] && v < id) continue;
        DFS(v, u, id);

        dp[u] = 1ll * dp[u] * (dp[v] + 1) % MOD;
    }
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> d >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 0;
    FOR(u, 1, n)
    {
        DFS(u, -1, u);
        Add(res, dp[u]);
    }

    cout << res;

    return 0;
}