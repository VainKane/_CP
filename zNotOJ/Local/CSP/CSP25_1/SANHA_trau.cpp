#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n, q;
int a[N], rb[N];

vector<int> adj[N];
bool visited[N];

void Init()
{
    stack<int> st;
    a[n + 1] = -1;

    FOR(i, 1, n + 1)
    {
        while (!st.empty() && a[i] <= a[st.top()])
        {
            rb[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void CreateGraph(int l, int r)
{
    memset(visited, false, sizeof visited);
    FOR(i, l, r) adj[i].clear();

    FOR(i, l, r) if (a[i] == a[rb[i]] && i != rb[i] && rb[i] <= r) 
    {
        adj[i].push_back(rb[i]);
        adj[rb[i]].push_back(i);
    }
}

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) if (!visited[v])
        {
            visited[v] = true;
            q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Init();

    while (q--)
    {
        int l, r;
        cin >> l >> r;
    
        CreateGraph(l, r);

        int cc = 0;
        FOR(u, l, r) if (!visited[u])
        {
            BFS(u);
            cc++;
        }

        cout << cc << '\n';
    }

    return 0;
}