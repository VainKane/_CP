#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;
int k;

int c[N];
vector<int> adj[N];
int dp[(1 << 5)][N];

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int TurnOff(int i, int mask)
{
    return mask & (~(1 << i));
}

int TurnOn(int i, int mask)
{
    return mask | (1 << i);
}

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k; 

    for (int i = 1; i <= n; i++) 
    {
        cin >> c[i];
        c[i] -= 1;
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

        dp[1 << c[u]][u] = 1;
        dp[1 << c[v]][v] = 1;
    }

    for (int mask = 0; mask < (1 << k); mask++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (!bit(c[u], mask)) continue;
            
            for (auto v : adj[u])
            {
                if (bit(c[v], mask)) continue;
                dp[TurnOn(c[v], mask)][v] += dp[mask][u];
            }
        }
    }

    for (int mask = 0; mask < (1 << k); mask++)
    {
        if (__builtin_popcount(mask) < 2) continue;

        for (int u = 1; u <= n; u++)
        {
            res += dp[mask][u];
        }
    }

    cout << res;

    return 0;
}