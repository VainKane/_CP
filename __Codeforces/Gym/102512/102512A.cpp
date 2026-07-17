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

int const N = 2e5 + 5;
int const LOG = 18;

int n, m;
vector<int> adj[N];
vector<int> tmpAdj[N];
vector<int> bcAdj[2 * N];

int in[N], low[N];
int blockId[N];

int up[2 * N][22];
int h[2 * N];

bool cut[2 * N];
int cnt[2 * N];

stack<int> st;
int timer = 0, bc = 0;

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u])
    {
        if (v == p) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);
        
            if (low[v] >= in[u])
            {
                tmpAdj[u].push_back(++bc);
                int node = 0;

                while (node != v)
                {
                    node = st.top(); st.pop();
                    in[node] = n + 1;
                    tmpAdj[node].push_back(bc);
                }
            }
        }
    }
}

void DFS(int u, int p)
{
    for (auto &v : bcAdj[u]) if (v != p)
    {
        cnt[v] = cnt[u] + cut[v];
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
    return cnt[u] + cnt[v] - 2 * cnt[p] + cut[p];
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

    FOR(u, 1, n) 
    {
        if (sz(tmpAdj[u]) >= 2)
        {
            blockId[u] = ++bc;
            cut[bc] = true;
            
            for (auto &v : tmpAdj[u])
            {
                bcAdj[v].push_back(bc);
                bcAdj[bc].push_back(v);
            }
        }
        else if (sz(tmpAdj[u]) == 1) blockId[u] = tmpAdj[u][0];
    }

    DFS(1, -1);

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        u = blockId[u]; v = blockId[v];
        cout << Query(u, v) - cut[u] - cut[v] * (u != v) << '\n';
    }
}