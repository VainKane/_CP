#include <bits/stdc++.h>

using namespace std;

int const N = 2009;

int n;
int h[N];
vector<int> adj[N];
bool inDeg[N];

int root;
int f[N];
int g[N];

void DFS(int u, int p)
{
    f[u] = h[u];
    for (auto v : adj[u])
    {
        if (v == p) continue;

        DFS(v, p);
        f[u] += g[v];
        g[u] += max(f[v], g[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        adj[k].push_back(l);

        inDeg[l] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!inDeg[i]) 
        {
            root = i;
            break;
        }
    }

    DFS(root, -1);
    cout << f[root];

    return 0;
}