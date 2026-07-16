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
int const LOG = 19;

int n, m, s, t;
vector<pair<int, bool>> adj[N];
vector<pair<int, bool>> bridgeAdj[N];

int in[N], low[N];
int timer = 0, cc = 0;

int ccId[N];
int val[N];

int up[N][21];
int h[N], cnt[N];

stack<int> st;

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;
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

        while(v != u)
        {
            v = st.top(); st.pop();
            in[v] = n + 1;
            ccId[v] = cc;  
        }
    }
}

void DFS(int u, int p)
{
    for (auto &e : bridgeAdj[u])
    {
        int v = e.F;
        bool w = e.S;

        if (v == p) continue;

        cnt[v] = cnt[u] + val[v] + w;
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
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

int Query(int u, int v)
{
    int p = LCA(u, v);
    return cnt[u] + cnt[v] - 2 * cnt[p] + val[p];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, z;
        cin >> u >> v >> z;
        adj[u].push_back({v, z});
        adj[v].push_back({u, z});
    }
    cin >> s >> t;

    Tarjan(1, -1);

    FOR(i, 1, n) for (auto &e : adj[i])
    {
        int u = ccId[i];
        int v = ccId[e.F];

        if (u == v) val[u] += e.S * (i < e.F);
        else bridgeAdj[u].push_back({v, e.S});
    }

    cnt[1] = val[1];

    DFS(1, -1);
    cout << (Query(ccId[s], ccId[t]) ? "YES\n" : "NO\n");

    return 0;
}