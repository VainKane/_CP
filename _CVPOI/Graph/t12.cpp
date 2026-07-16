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

int type, n, m;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> revAdj[N];

int low[N], in[N];
int timer = 0, cc = 0;

stack<int> st;
int ccId[N];

bool mark[N];
int d[N];

void Tarjan(int u)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (ccId[v]) continue;
        
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v);
            mini(low[u], low[v]);
        }
    }

    if (low[u] == in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st.top(); st.pop();
            ccId[v] = cc;
        }
    }
}

void Dijkstra(int cen)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    memset(d, 0x3f, sizeof d);
    FOR(u, 1, n) if (ccId[u] == cen)
    {
        d[u] = 0;
        pq.push({d[u], u});
    }

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : revAdj[u])
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

    cin >> type >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        revAdj[v].push_back({u, w});
    }

    FOR(u, 1, n) if (!in[u]) Tarjan(u);

    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i];
        int v = ccId[j.F];

        if (u == v) continue;
        mark[u] = true;
    }

    FOR(id, 1, cc) if (!mark[id])
    {
        if (type == 1) FOR(u, 1, n) if (ccId[u] == id) cout << u << ' ';
        if (type == 2)
        {
            Dijkstra(id);
            FOR(u, 1, n) cout << d[u] << ' ';
        }
        return 0;
    }

    return 0;
}