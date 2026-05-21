#include <bits/stdc++.h>

using namespace std;

int const N = 5e4 + 5;

int n;
int m;
int k;
int l;

bool a[N];
bool b[N];
vector<int> adj[N];

int par[N];
int id[N];
int low[N];

int cntA[N];
int cntB[N];

int cnt = 0;
int res = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    cntA[u] += a[u];
    cntB[u] += b[u];

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            cntA[u] += cntA[v];
            cntB[u] += cntB[v];
            
            if (low[v] == id[v])
            {
                if (cntA[v] * cntB[v] == 0 || (cntA[v] == k) || (cntB[v] == l)) res++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> l;
    
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }

    for (int i = 1; i <= l; i++)
    {
        int x;
        cin >> x;
        b[x] = 1;
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) if (!id[i]) DFS(i);
    cout << res;

    return 0;
}