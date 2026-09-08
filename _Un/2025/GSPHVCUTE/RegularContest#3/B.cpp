#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "longtrip"

int const N = 55;

long long d[N][(int)2e4 + 5];

struct Data
{
    long long du;
    int u, r;

    bool operator < (Data const other) const
    {
        return du > other.du;
    }
};

int n, m;

long long t;
vector<pair<int, int>> adj[N];

int c = 1e4;

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1][0] = 0;

    priority_queue<Data> q;
    q.push(Data {0, 1, 0});

    while (!q.empty())
    {
        long long du = q.top().du;
        int u = q.top().u;
        int r = q.top().r;
        q.pop();

        if (du > d[u][r]) continue;

        for (auto e : adj[u])
        {
            int v = e.F;
            int w = e.S;
            int newR = (r + w) % (2 * c);

            if (d[v][newR] > d[u][r] + w)
            {
                d[v][newR] = d[u][r] + w;
                q.push(Data {d[v][newR], v, newR});
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

    cin >> n >> m >> t;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        if (u == 1 || v == 1) c = w;
    }

    Dijkstra();
    cout << ((d[n][t % (2 * c)] <= t) ? "Possible" : "Impossible");

    return 0;
}