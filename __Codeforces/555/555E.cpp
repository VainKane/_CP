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
int const LOG = 19;

int n, m, q;
vector<int> adj[N];
vector<int> bridgeAdj[N];

int low[N], in[N];
int timer = 0, cc = 0;

int ccId[N];
stack<int> st;

int h[N];
int up[N][25];

bool visited[N];
int f1[N], f2[N];

int cpId[N];
int cnt = 0;

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u])
    {
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
        }
    }
}

void DFSPrepare(int u, int p)
{
    cpId[u] = cnt;
    for (auto &v : bridgeAdj[u]) if (v != p && !cpId[v])
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFSPrepare(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (h[up[u][i]] >= h[v]) u = up[u][i];

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void DFS(int u, int p)
{
    visited[u] = true;
    for (auto &v : bridgeAdj[u]) if (!visited[v])
    {
        DFS(v, u);
        f1[u] += f1[v];
        f2[u] += f2[v];
    }
}

void PrintNo()
{
    cout << "No\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(u, 1, n) if (!in[u]) Tarjan(u, -1);
    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i];
        int v = ccId[j];

        if (u == v) continue;

        bridgeAdj[u].push_back(v);
    }

    FOR(u, 1, cc) sort(all(bridgeAdj[u]));

    FOR(u, 1, cc) if (!cpId[u])
    {
        cnt++;
        DFSPrepare(u, -1);
    }

    h[0] = -1;

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        u = ccId[u]; v = ccId[v];
        int p = LCA(u, v);

        f1[u]++; f1[p]--;
        f2[v]++; f2[p]--;

        if (cpId[u] != cpId[v]) PrintNo();
    }

    FOR(u, 1, n) if (!visited[u]) DFS(u, -1);

    FOR(u, 1, cc) for (auto &v : bridgeAdj[u])
    {
        if (h[v] < h[u]) continue;
        if (upper_bound(all(bridgeAdj[u]), v) - lower_bound(all(bridgeAdj[u]), v) > 1) continue;
        if (!f1[v] || !f2[v]) continue;

        PrintNo();
    }

    cout << "Yes\n";

    return 0;
}