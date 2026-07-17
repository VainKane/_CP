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

int const N = 2e5 + 5;
int const M = 5e5 + 5;
int const MOD = 998244353;

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

Edge edges1[M];
pair<int, int> edges2[N];

vector<int> adj[N];
long long d[N];

int deg1[N], deg2[N];
int pw[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({d[1], 1});

    FOR(i, 1, k)
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

    pw[0] = 1;
    FOR(i, 1, k) pw[i] = 2 * pw[i - 1] % MOD;

    Dijkstra();

    FOR(i, 1, m)
    {
        int u = edges1[i].u, v = edges1[i].v;
        int w = edges1[i].w;

        if (d[u] + w == d[v]) deg1[v]++;
        if (d[v] + w == d[u]) deg1[u]++;
    }

    int res = 1;

    FOR(i, 1, k)
    {
        if (edges2[i].S == d[edges2[i].F]) deg2[edges2[i].F]++;
        else res = 2 * res % MOD;
    }

    FOR(u, 1, n)
    {
        if (deg1[u]) res = 1LL * res * pw[deg2[u]] % MOD;
        else if (deg2[u]) res = 1LL * res * (pw[deg2[u]] - 1 + MOD) % MOD;
    }

    cout << res;

    return 0;
}