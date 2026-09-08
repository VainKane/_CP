#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 5;

int n;
int m;

int a[N];
int s;
int p;

vector<int> adj[N];
stack<int> st;

int low[N];
int id[N];
int in[N];

int cnt = 0;
int scc = 0;

bool game[N];

vector<int> topo;
set<int> dagAdj[N];

int d[N];

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
        scc++;
        int v = 0;
        int s = 0;

        while (u != v)
        {
            v = st.top();
            st.pop();

            id[v] = n + 1;
            s += a[v];
            in[v] = u;

            if (game[v]) game[u] = true;
        }

        a[u] = s;
    }
}

void DFS(int u)
{
    id[u] = 1;
    if (game[u]) d[u] = a[u];
    // else d[u] = -2e9;

    for (auto v : dagAdj[u])
    {
        if (!id[v]) DFS(v);
    }

    topo.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) 
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) cin >> a[i];
    
    cin >> s >> p;

    for (int i = 1; i <= p; i++)
    {
        int x;
        cin >> x;

        game[x] = true;
    }

    for (int i = 1; i <= n; i++) if (!id[i]) Tarjan(i);

    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            if (in[u] == in[v]) continue;
            if (dagAdj[in[u]].count(in[v])) continue;
 
            dagAdj[in[u]].insert(in[v]);
            id[in[u]] = id[in[v]] = 0;
        }
    }

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);    

    // for (auto u : topo) cout << u << ' ';
    // for (int u = 1; u <= n; u++)
    // {
    //     cout << u << " : ";
    //     for (auto v : dagAdj[u]) cout << v << ' ' ;
    //     cout << '\n';
    // }

    for (auto u : topo)
    {
        for (auto v : dagAdj[u])
        {
            if (!game[v]) continue;
            d[u] = max(d[u], d[v] + a[u]);
            game[u] = true;
        }
    }

    cout << d[in[s]];

    return 0;
}