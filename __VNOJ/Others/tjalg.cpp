#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e4 + 5;

int n, m;
vector<int> adj[N];

int id[N], low[N];
int timer = 0;

stack<int> st;
int scc = 0;

void Tarjan(int u, int p)
{
    low[u] = id[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u])
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v, u);
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
            id[v] = n + 1;
        }

        scc++;
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
    }

    FOR(u, 1, n) if (!id[u]) Tarjan(u, -1);
    cout << scc;

    return 0;
}