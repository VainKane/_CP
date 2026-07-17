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

struct Edge
{
    int u, v, f;
    int pos[2];

    void Input()
    {
        cin >> u >> v >> f;
    }

    bool Type(int p)
    {
        return p == u;
    }

    int Node(bool type)
    {
        return type ? u : v;
    }
};

struct State
{
    long long du;
    int id, type;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 2e5 + 5;
long long const oo = 1e18;

int n, m;

vector<int> adj[N];
Edge edges[N];

long long d[N][2];

void Dijkstra()
{
    priority_queue<State> pq;
    memset(d, 0x3f, sizeof d);

    for (auto &id : adj[1])
    {
        bool type = edges[id].Type(1);
        d[id][type] = 0;
        pq.push({0, id, type});
    }

    while (!pq.empty())
    {
        int id = pq.top().id;
        bool type = pq.top().type;
        long long du = pq.top().du;
        pq.pop();

        int u = edges[id].Node(type);
        int pos = edges[id].pos[type];
        int f = edges[id].f;

        if (pos > 0)
        {
            int newId = adj[u][pos - 1];
            int newType = edges[newId].Type(u);
            
            if (mini(d[newId][newType], d[id][type] + f - edges[newId].f))
                pq.push({d[newId][newType], newId, newType});
        }

        if (pos < sz(adj[u]) - 1)
        {
            int newId = adj[u][pos + 1];
            int newType = edges[newId].Type(u);

            if (mini(d[newId][newType], d[id][type] + edges[newId].f - f))
                pq.push({d[newId][newType], newId, newType});
        }

        if (mini(d[id][!type], d[id][type] + (u == 1 ? f : 0))) pq.push({d[id][!type], id, !type});
    }
}

bool cmp(int i, int j)
{
    return edges[i].f < edges[j].f;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        edges[i].Input();
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    FOR(u, 1, n)
    {
        sort(all(adj[u]), cmp);
        REP(i, sz(adj[u]))
        {
            Edge &tmp = edges[adj[u][i]];
            tmp.pos[tmp.Type(u)] = i;
        }
    }

    Dijkstra();

    long long res = oo;
    for (auto &id : adj[n]) mini(res, d[id][edges[id].Type(n)]);
    if (res == oo) res = -1;

    cout << res;

    return 0;
}