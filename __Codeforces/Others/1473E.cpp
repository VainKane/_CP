#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Data
{
    int u, added, subed;
    long long du;

    bool operator < (Data const other) const
    {
        return du > other.du;
    }
};

int const N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
long long d[N][2][2];

void Dijkstra()
{
    priority_queue<Data> pq;
    memset(d, 0x3f, sizeof d);

    pq.push({1, 0, 0, 0});
    d[1][0][0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().u;
        bool added = pq.top().added;
        bool subed = pq.top().subed;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][added][subed]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v][added][subed], d[u][added][subed] + w)) 
                pq.push({v, added, subed, d[v][added][subed]});

            if (!added && mini(d[v][1][subed], d[u][0][subed] + 2 * w))
                pq.push({v, 1, subed, d[v][1][subed]});

            if (!subed && mini(d[v][added][1], d[u][added][0]))
                pq.push({v, added, 1, d[v][added][1]});
            
            if (!added && !subed && mini(d[v][1][1], d[u][0][0] + w))
                pq.push({v, 1, 1, d[v][1][1]});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra();
    FOR(u, 2, n) cout << d[u][1][1] << ' ';

    return 0;
}