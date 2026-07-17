#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

vector<int> adj[N];

int low[N];
int id[N];
stack<int> st;
vector<int> res[N];

int cnt = 0;
int scc = 0;

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
        scc++;

        int v = 0;
        while (v != u)
        {
            v = st.top();
            st.pop();
            id[v] = n + 1;
            res[scc].push_back(v);
        }

        sort(res[scc].begin(), res[scc].end());
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    return *a.begin() < *b.begin();
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

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);
    sort(res + 1, res + scc + 1, cmp);
    
    cout << scc << '\n';
    for (int i = 1; i <= scc; i++)
    {
        cout << res[i].size() << '\n';
        for (auto val : res[i]) cout << val << ' ';
        cout << '\n';
    }

    return 0;
}