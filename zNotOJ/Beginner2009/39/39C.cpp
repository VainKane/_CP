#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

struct Edge
{
    int v, w, i;
};

int const N = 1e5 + 5;

int n, k;
double v1, v2;

vector<Edge> adj[N];
double delta;

bool visited[N];
int child[N];
int deg[N];

vector<double> b;

double res = 0;

void DFS(int u)
{
    child[u]++;
    visited[u] = true;
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;
        if (visited[v]) continue;
        
        DFS(v);
        child[u] += child[v];
        b.push_back((double)child[v] * (n - child[v]) * w * delta);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(2);

    cin >> n >> k >> v1 >> v2;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
        deg[u]++;
        deg[v]++;
    }
 
    delta = 1 / v1 - 1 / v2;

    for (int u = 1; u <= n; u++)
    {
        if (deg[u] == 1)
        {
            DFS(u);
            break;
        }
    }

    sort(all(b), greater<double> ());
    for (int i = 0; i < k; i++) res += b[i];

    cout << res;

    return 0;
}