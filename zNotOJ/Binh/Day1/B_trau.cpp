#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "GRAPH"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int v;
    long long p, w;
};

int const N = 2e5 + 5;
int const M = 3e5 + 5;
long long const oo = 2e18;

int n, m;
vector<Edge> adj[N];

long long a[M];
long long d[N];

void Dijkstra(int &idx)
{
    FOR(i, 2, n) d[i] = oo;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();
    
        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.v;
            long long p = e.p;
            long long w = e.w;

            if (p > a[idx]) continue;
            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        long long w;
        cin >> u >> v >> a[i] >> w;
        adj[u].push_back({v, a[i], w});
        adj[v].push_back({u, a[i], w});
    }

    sort(a + 1, a + m + 1);

    int l = 1;
    int r = m;
    pair<int, long long> res;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        Dijkstra(mid);

        if (d[n] != oo)
        {
            res = {mid, d[n]};
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << a[res.F] << ' ' << res.S;

    return 0;
}