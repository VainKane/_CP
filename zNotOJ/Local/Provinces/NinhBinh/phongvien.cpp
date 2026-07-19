#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int n, m;
vector<int> adj[N];

int scc = 0;

int cnt = 0;
int id[N], low[N];
int in[N];

stack<int> st;

void Tarjan(int u)
{
    low[u] = id[u] = ++cnt;
    st.push(u);

    for (auto v : adj[u])
    {
        if (in[v]) continue;
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
        int v = u;
        do
        {
            v = st.top();
            id[v] = n + 1;
            in[v] = scc;

            st.pop();
        } while (v != u);
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

    FOR(i, 1, n) if (!id[i]) Tarjan(i);

    cout << scc;

    return 0;
}