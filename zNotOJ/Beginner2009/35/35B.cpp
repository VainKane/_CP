#include <bits/stdc++.h>

using namespace std;

#define name "35B"
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n;
int m;

vector<int> adj[N];

int id[N];
int low[N];
stack<int> st;

unordered_set<int> mark[N];

int cnt = 0;
int scc = 0;

int vertices[N];
int edges[N];
int sccId[N];

long long res = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    st.push(u);

    for (auto v : adj[u])
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == id[u])
    {
        int v = 0;
        scc++;

        while (v != u)
        {
            v = st.top();
            st.pop();

            id[v] = n + 1;
            vertices[scc]++;
            sccId[v] = scc;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        if (!mark[u].count(v))
        {
            adj[u].push_back(v);
            mark[u].insert(v);
        }
    }

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);
    for (int u = 1; u <= n; u++) 
    {
        for (auto v : adj[u])
        {
            if (sccId[u] == sccId[v])
            {
                if (!mark[u].count(v)) continue;
                edges[sccId[v]]++;
            }
        }
    }

    for (int i = 1; i <= scc; i++)
    {
        res += vertices[i] * (vertices[i] - 1ll) - edges[i];
    }
    cout << res;

    return 0;
}