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

int n, m, k;
vector<pair<int, int>> adj[N];
pair<int, int> e[N];

long long d[N];
int deg1[N], deg2[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({d[1], 1});

    FOR(i, 1, k) if (mini(d[e[i].F], 1LL * e[i].S)) pq.push({d[e[i].F], e[i].F});

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

    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    FOR(i, 1, k) cin >> e[i].F >> e[i].S;

    Dijkstra();

    FOR(u, 1, n) for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        deg1[v] += d[u] + w == d[v];
    }

    int res = 0;

    FOR(i, 1, k)
    {
        if (e[i].S == d[e[i].F]) deg2[e[i].F]++;
        else res++;
    }

    FOR(u, 1, n)
    {
        if (deg1[u]) res += deg2[u];
        else if (deg2[u]) res += deg2[u] - 1;
    }

    cout << res;

    return 0;
}