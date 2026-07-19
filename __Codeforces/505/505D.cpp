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

int const N = 1e5 + 5;

int n, m;
vector<int> adj[N];
vector<int> adj2[N];

int ccId[N];

int in[N], low[N];
int timer = 0, cc = 0;

stack<int> st;
int scc[N];

bool visited[N];
int cnt[N];
int chain = 0;

bool cycle[N];

void Tarjan(int u)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u])
    {
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
            scc[cc]++;
        }
    }
}

void DFS(int u, int &id)
{
    visited[u] = true;
    cycle[id] |= (scc[ccId[u]] > 1);
    cnt[id]++;

    for (auto &v : adj2[u]) if (!visited[v]) DFS(v, id);
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
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    FOR(u, 1, n) if (!in[u]) Tarjan(u);
    FOR(u, 1, n) if (!visited[u]) DFS(u, ++chain);

    int res = 0;
    FOR(id, 1, chain) res += cnt[id] - 1 + cycle[id];
    cout << res;

    return 0;
}