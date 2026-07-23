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
#define name "BALLOON"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

struct Edge
{
    int u, v, w;
    void Input() { cin >> u >> v >> w; }
    int Other(int node) { return node ^ u ^ v; }
};

int n, m;
vector<int> adj[N];

ll d[N], dist[N];
Edge edges[N];

bool mark[N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({d[0], 0});

    while (!pq.empty())
    {
        int u = pq.top().S;
        ll du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &id : adj[u]) if (mark[id])
        {
            int v = edges[id].Other(u);
            int w = edges[id].w;

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

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    REP(i, m)
    {
        edges[i].Input();
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    memset(mark, true, sizeof mark);
    Dijkstra();
    FOR(u, 1, n) dist[u] = d[u];

    int cnt = m + 1;
    ll res = 0;

    REP(mask, MK(m))
    {
        REP(i, m) mark[i] = BIT(i, mask);
        Dijkstra();
        
        if (Check())
        {
            ll sum = 0;
            REP(i, m) sum += mark[i] * edges[i].w;
            int k = __builtin_popcount(mask);
            if (mini(cnt, k) || cnt == k) maxi(res, sum);
        }
    }

    cout << m - cnt << ' ' << res;

    return 0;
}