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
#define name "GIDDY"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5e4 + 5;

int n, m, k;
vector<pair<int, int>> adj[N];
vector<pair<int, long long>> nodes;

long long dn[N], dk[N];

void Dijkstra(long long d[], vector<pair<int, long long>> nodes)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    memset(d, 0x3f, (n + 1) * sizeof (long long));
    for (auto &p : nodes)
    {
        d[p.F] = p.S;
        pq.push({d[p.F], p.F});
    }

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
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

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> k;

    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra(dn, {{n, 0}});

    while (k--)
    {
        int u, c; cin >> u >> c;
        nodes.push_back({u, dn[u] - c});
    }

    Dijkstra(dk, nodes);
    
    FOR(i, 1, n - 1) cout << (dk[i] <= dn[i]) << '\n';

    return 0;
}