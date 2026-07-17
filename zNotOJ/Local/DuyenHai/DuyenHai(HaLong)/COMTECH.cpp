#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

#define name "COMTECH"

int n;
int m;

vector<int> adj[N];
set<int> dagAdj[N];

stack<int> st;
int low[N];
int id[N];
int in[N];

int inDeg[N];
int outDeg[N];

int cnt = 0;

void Tarjan(int u)
{
    low[u] = id[u] = ++cnt;
    st.push(u);

    for (auto v : adj[u])
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == id[u])
    {
        int v = 0;

        while (v != u)
        {
            v = st.top();
            st.pop();

            in[v] = u;
            id[v] = n + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) if (!id[i]) Tarjan(i);

    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            if (in[v] == in[u]) continue;
            if (dagAdj[u].count(v)) continue;
            
            dagAdj[u].insert(v);
            inDeg[v]++;
            outDeg[u]++;
        }
    }

    int cntIn = 0;
    int cntOut = 0;

    for (int u = 1; u <= n; u++)
    {
        if (inDeg[u] == 0) cntIn++;
        if (outDeg[u] == 0) cntOut++;
    }

    cout << max(cntIn, cntOut);

    return 0;
}