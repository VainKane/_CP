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

int const N = 67;

struct Edge
{
    int u, v, w;

    void Input()
    {
        cin >> u >> v >> w;
    }

    int GetOther(int node)
    {
        return node ^ u ^ v;
    }
};

int n, m, k;

Edge edges1[N];
pair<int, int> edges2[N];

vector<int> adj[N];
long long d[N], dist[N];

bool mark[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({d[1], 1});

    FOR(i, 1, k) if (!mark[i])
    {
        int u = edges2[i].F;
        int w = edges2[i].S;

        if (mini(d[u], 1LL * w)) pq.push({d[u], u});
    }

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;
        
        for (auto &id : adj[u])
        {
            int v = edges1[id].GetOther(u);
            int w = edges1[id].w;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

bool Check()
{
    FOR(u, 1, n) if (dist[u] != d[u]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        edges1[i].Input();
        adj[edges1[i].u].push_back(i);
        adj[edges1[i].v].push_back(i);
    }
    FOR(i, 1, k) cin >> edges2[i].F >> edges2[i].S;

    Dijkstra();
    FOR(u, 1, n) dist[u] = d[u];

    int res = 0;

    REP(mask, MK(k))
    {
        REP(i, k) mark[i + 1] = BIT(i, mask);
        Dijkstra();
        res += Check();
    }

    cout << res;

    return 0;
}