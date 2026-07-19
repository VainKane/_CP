#include <bits/stdc++.h>

using namespace std;

#define BIT(i, mask) (((mask) >> (i)) & 1)
#define MASK(i) (1 << (i))
#define ON(i, mask) ((mask) | (1 << (i)))
#define F first
#define S second
#define name "banhkhuc"

int const N = 509;
int const K = 25;

int n, k;
int a[N];
int b[N];

int c[N][N];
int d[N][N];

long long dp[(1 << 20) + 5][K];
long long res = 1e18;

void Dijkstra(int s, int d[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (int v = 1; v <= n; v++)
        {
            int w = c[u][v];

            if (v == u) continue;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> c[i][j];
        a[i] = i;
    }

    for (int i = 1; i <= k; i++) cin >> b[i];

    b[0] = 1;
    for (int i = 0; i <= k; i++)
    {
        int x = b[i];

        memset(d[x], 0x3f, sizeof d[x]);
        Dijkstra(x, d[x]);
    }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < k; i++) 
    {
        dp[MASK(i)][i] = d[1][b[i + 1]];
    }

    for (int mask = 0; mask < MASK(k); mask++)
    {
        for (int tmp = mask; tmp > 0; tmp -= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            for (int huhu = (MASK(k) - 1) ^ mask; huhu > 0; huhu -= huhu & -huhu)
            {
                int j = __builtin_ctz(huhu & -huhu);
                dp[ON(j, mask)][j] = min(dp[ON(j, mask)][j], dp[mask][i] + d[b[i + 1]][b[j + 1]]);
            }
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        res = min(res, dp[MASK(k) - 1][i] + d[b[i + 1]][1]);
    }

    cout << res;
}