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

int const N = 25;

int n, m;

pair<int, int> edges[N];
vector<int> adj[N];
vector<int> dagAdj[N];

bool visited[N];
int inDeg[N];

vector<int> topo;
bitset<N> go[N];

stack<int> st;
int ccId[N];
vector<int> scc[N];

int in[N], low[N];
int timer = 0, cc = 0;

void Tarjan(int u)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u])
    {
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
            in[v] = n + 1;
            ccId[v] = cc;
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, cc) if (!inDeg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto &v : dagAdj[u]) if (!--inDeg[v]) q.push(v);
    }
}

void Reset()
{
    memset(inDeg, 0, sizeof inDeg);
    memset(in, 0, sizeof in);

    FOR(u, 1, n) 
    {
        adj[u].clear();
        scc[u].clear();
        dagAdj[u].clear();
        go[u] = 0;
    }

    timer = cc = 0;

    topo.clear();
    st = stack<int> ();
}

bool Check()
{
    FOR(u, 1, n) if (!in[u]) Tarjan(u);

    FOR(u, 1, n) scc[ccId[u]].push_back(u);
    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i];
        int v = ccId[j];

        if (u == v) continue;
        dagAdj[u].push_back(v);
        inDeg[v]++;
    }

    FOR(u, 1, cc)
    {
        sort(all(dagAdj[u]));
        dagAdj[u].erase(unique(all(dagAdj[u])), dagAdj[u].end());
    }

    BFS();

    for (auto &u : topo) for (auto &v : dagAdj[u])
    {
        go[v] |= go[u];
        go[v][u] = true;
        go[u][u] = true;
    }

    REP(i, m) 
    {
        int u = ccId[edges[i].F];
        int v = ccId[edges[i].S];
        if (!go[v][u]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, m) cin >> edges[i].F >> edges[i].S;

    int res = m;

    REP(mask, MK(m))
    { 
        Reset();

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            adj[edges[i].F].push_back(edges[i].S);
        }

        if (Check()) mini(res, __builtin_popcount(mask));
    }

    cout << res;

    return 0;
}