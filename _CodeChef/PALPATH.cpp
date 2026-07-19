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

struct State
{
    long long du;
    int u, v;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 1009;
long long const oo = 1e18;

int n, m, s, t;
vector<pair<int, int>> adj[N][30];

long long d[N][N];

void Dijkstra()
{
    priority_queue<State> pq;
    memset(d, 0x3f, sizeof d);

    FOR(u, 1, n)
    {
        d[u][u] = 0;
        pq.push({0, u, u});

        REP(c, 26) for (auto &e : adj[u][c]) mini(d[u][e.F], 1LL * e.S);
        REP(c, 26) for (auto &e : adj[u][c])
        {
            int v = e.F;
            if (d[u][v] < oo) pq.push({d[u][v], u, v});
        }
    }

    while (!pq.empty())
    {
        int u = pq.top().u;
        int v = pq.top().v;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][v]) continue;
    
        REP(c, 26) for (auto &e1 : adj[u][c]) for (auto &e2 : adj[v][c])
        {
            int x = e1.F;
            int y = e2.F;
            
            if (mini(d[x][y], d[u][v] + e1.S + e2.S)) pq.push({d[x][y], x, y});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tests; cin >> tests;
    while (tests--)
    {
        cin >> n >> m >> s >> t;

        FOR(u, 1, n) REP(c, 26) adj[u][c].clear();
        FOR(i, 1, m)
        {
            int u, v, w; char c;
            cin >> u >> v >> w >> c;

            adj[u][c - 'a'].push_back({v, w});
            adj[v][c - 'a'].push_back({u, w});
        }

        Dijkstra();
        cout << (d[s][t] < oo ? d[s][t] : -1) << '\n';
    }

    return 0;
}