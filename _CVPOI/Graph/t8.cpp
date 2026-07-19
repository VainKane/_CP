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
long long const oo = 1e18;

int n, m, k;

int city[36];
vector<pair<int, int>> adj[N];

int d[36][N];
long long dp[MK(15) + 5][36];

void Dijkstra(int d[], int s)
{
    memset(d, 0x3f, (n + 1) * sizeof(int));
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;
            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    REP(i, k) cin >> city[i];

    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if (k == 0)
    {
        Dijkstra(d[0], 1);
        cout << d[0][n];
        return 0;
    }

    REP(i, k) Dijkstra(d[i], city[i]);

    memset(dp, 0x3f, sizeof dp);
    REP(i, k) dp[MK(i)][i] = d[i][1];

    REP(mask, MK(k)) for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        for (int haha = mask ^ (MK(k) - 1); haha; haha ^= haha & -haha)
        {
            int j = __builtin_ctz(haha);
            mini(dp[mask | MK(j)][j], dp[mask][i] + d[i][city[j]]);
        }
    }

    long long res = oo;
    REP(i, k) mini(res, dp[MK(k) - 1][i] + d[i][n]);
    cout << res;

    return 0;
}
