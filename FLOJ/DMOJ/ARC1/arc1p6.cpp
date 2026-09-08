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

struct State
{
    int u;
    bool vis;
    long long du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int n, m, q, x, y;

int a[N];
vector<int> adj[N];

long long d[N][2], dy[N];

void DijkstraPrepare()
{
    memset(dy, 0x3f, sizeof dy);
    dy[y] = a[y];

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({dy[y], y});

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > dy[u]) continue;
        for (auto &v : adj[u]) if (mini(dy[v], dy[u] + a[v])) pq.push({dy[v], v});
    }
}

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[x][0] = a[x], d[x][1] = dy[x];

    priority_queue<State> pq;
    pq.push({x, 0, d[x][0]});
    pq.push({x, 1, d[x][1]});

    while (!pq.empty())
    {
        int u = pq.top().u;
        bool vis = pq.top().vis;
        long long du = pq.top().du;
        pq.pop();

        if (!vis && mini(d[u][1], du + dy[u] - a[u])) pq.push({u, 1, d[u][1]});
        for (auto &v : adj[u]) if (mini(d[v][vis], d[u][vis] + a[v])) pq.push({v, vis, d[v][vis]});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x >> y >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DijkstraPrepare();
    Dijkstra();

    while (q--)
    {
        int u; cin >> u;
        cout << d[u][1] << '\n';
    }

    return 0;
}