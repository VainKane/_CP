#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "longtrip"

int const N = 55;

int n, m, t;
vector<pair<int, int>> adj[N];
bool dp[(int)1e5 + 5][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m >> t;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dp[0][1] = true;

    FOR(i, 1, t) FOR(u, 1, n) for (auto e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (i - w < 0) continue;

        dp[i][u] |= dp[i - w][v];
        if (dp[i][u]) break;
    }

    cout << (dp[t][n] ? "Possible" : "Impossible");

    return 0;
}