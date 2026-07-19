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

int const N = 4e5 + 5;

struct Edge
{
    int u, v;

    int GetOther(int p)
    {
        return p ^ u ^ v;
    }
};

int n, m;

vector<int> adj[N];
Edge edges[N];

int low[N], in[N];
int timer = 0, cc = 0;

stack<int> st;
int res = 0;

bool used[N];

int scc[N];
int ccId[N];

int maxCC;
int cnt = 0;

int pos[N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u);

        if (u != edges[id].u && !used[id]) swap(edges[id].u, edges[id].v);
        used[id] = true;
        
        if (v == p || ccId[v]) continue;

        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
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
            scc[cc]++;
        }

        if (maxi(res, scc[cc])) maxCC = cc;
    }
}

void DFS(int u, int p)
{
    pos[u] = ++cnt;
    for (auto &v : adj[u]) if (v != p) DFS(v, u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(i);
        adj[v].push_back(i);
        edges[i] = {u, v};
    }

    Tarjan(1, -1);

    FOR(u, 1, n) adj[u].clear();
    FOR(i, 1, m)
    {
        int u = ccId[edges[i].u];
        int v = ccId[edges[i].v];

        if (u == v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(maxCC, -1);

    cout << res << '\n';
    FOR(i, 1, m)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (pos[ccId[u]] < pos[ccId[v]]) swap(u, v);
        cout << u << ' ' << v << '\n';
    }

    return 0;
}