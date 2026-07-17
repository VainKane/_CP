#include <bits/stdc++.h>

using namespace std;

int const MOD = 2017;
int const N = 59;

int n;
int m;
int k;

vector<int> adj[N];
int dp[(int)1e5][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("23D.inp", "r", stdin);
    freopen("23D.ans", "w", stdout);

    cin >> n >> m >> k;
    
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    for (auto u : adj[1]) dp[1][u]++;

    for (int i = 2; i <= k; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                dp[i][v] = (dp[i][v] + dp[i - 1][u]) % MOD;
            }
        }
    }

    cout << dp[k][n];

    return 0;
}