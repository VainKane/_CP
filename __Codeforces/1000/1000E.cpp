#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

int const N = 3e5 + 5;

int n, m;
vector<int> adj[N];
vector<int> bridgeAdj[N];

int f[N], g[N];
int fPar[N];

int ccId[N];

int in[N], low[N];
int timer = 0, cc = 0;

stack<int> st;

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
    for (auto &v : bridgeAdj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        if (f[v] + 1 > f[u])
        {
            g[u] = f[u];
            f[u] = f[v] + 1;
        }
        else maxi(g[u], f[v] + 1);
    }
}

void DFS(int u, int p)
{
    for (auto &v : bridgeAdj[u]) if (v != p)
    {
        int maxChild = f[u] == f[v] + 1 ? g[u] : f[u];
        fPar[v] = max(maxChild, fPar[u]) + 1;
        DFS(v, u);
    }
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tarjan(1, -1);

    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i];
        int v = ccId[j];

        if (u == v) continue;
        bridgeAdj[u].push_back(v);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    int res = 0;
    FOR(u, 1, n) maxi(res, fPar[ccId[u]] + f[ccId[u]]);
    cout << res;

    return 0;
}