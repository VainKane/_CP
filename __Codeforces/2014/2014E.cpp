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
    int u;
    bool horse;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 2e5 + 5;
long long const oo = 1e18;

int n, m, h;
vector<pair<int, int>> adj[N];
bool mark[N];

long long d1[N][2];
long long d2[N][2];

void Dijkstra(int s, long long d[][2])
{
    priority_queue<State> pq;
    pq.push({0, s, mark[s]});

    FOR(i, 1, n) REP(j, 2) d[i][j] = oo;
    d[s][mark[s]] = 0;

    while (!pq.empty())
    {
        int u = pq.top().u;
        bool horse = pq.top().horse;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][horse]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = horse ? (e.S >> 1) : e.S;
            bool newHorse = horse | mark[v];

            if (mini(d[v][newHorse], d[u][horse] + w)) pq.push({d[v][newHorse], v, newHorse});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> h;

        FOR(u, 1, n) 
        {
            adj[u].clear();
            mark[u] = false;
        }

        FOR(i, 1, h)
        {
            int u; cin >> u;
            mark[u] = true;
        }

        FOR(i, 1, m)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        Dijkstra(1, d1);
        Dijkstra(n, d2);

        long long res = oo;
        FOR(u, 1, n)
        {
            long long x = min(d1[u][0], d1[u][1]);
            long long y = min(d2[u][0], d2[u][1]);
            mini(res, max(x, y));
        }

        if (res == oo) res = -1;
        cout << res << '\n';
    }

    return 0;
}