#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
vector<pair<int, long long>> dagAdj[N];

int id[N], low[N];
int timer = 0;

int sccId[N];
int scc = 0;

stack<int> st;

long long val[N];
long long dp[N];

bool visited[N];

long long GetVal(int x)
{
    long long res = 0;
    while (x)
    {
        res += x;
        x >>= 1;
    }
    return res;
}

void Tarjan(int u)
{
    low[u] = id[u] = ++timer;
    st.push(u);

    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (sccId[v]) continue;
        
        if (id[v]) mini(low[u], id[v]);
        else
        {
            Tarjan(v);
            mini(low[u], low[v]);
        }
    }

    if (low[u] == id[u])
    {
        scc++;
        int v = 0;
        
        while (v != u)
        {
            v = st.top();
            sccId[v] = scc;
            st.pop();    
        }
    }
}

void DFS(int u)
{
    visited[u] = true;
    dp[u] = val[u];

    for (auto &e : dagAdj[u])
    {
        int v = e.F;
        long long w = e.S;

        if (!visited[v]) DFS(v);
        maxi(dp[u], dp[v] + val[u] + w);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    FOR(u, 1, n) if (!id[u]) Tarjan(u);
    FOR(i, 1, n) for (auto &e : adj[i])
    {
        int u = sccId[i];
        int v = sccId[e.F];
        int w = e.S;

        if (u == v) val[u] += GetVal(w); 
        else dagAdj[u].push_back({v, w});
    }

    FOR(u, 1, scc) 
    {
        sort(all(dagAdj[u]));
        dagAdj[u].erase(unique(all(dagAdj[u])), dagAdj[u].end());
    }

    DFS(sccId[1]);
    cout << dp[sccId[1]];

    return 0;
}
