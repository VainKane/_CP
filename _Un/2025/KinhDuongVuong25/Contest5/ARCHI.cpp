#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 2e6 + 5;
int const os = 1001;

vector<int> adj[N];
int n;

int id[2009][2009];
bool visited[N];

vector<int> ccNodes[N];
int deg[N];

int cc = 0;

void DFS(int u, int p, int &cc)
{
    visited[u] = true;
    ccNodes[cc].push_back(u);
    for (auto &v : adj[u]) if (!visited[v]) DFS(v, u, cc);
}

int GetId(int x, int y)
{
    if (id[x][y]) return id[x][y];
    return id[x][y] = ++n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m; cin >> m;
    while (m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += os; y1 += os;
        x2 += os; y2 += os;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        if (x1 == x2) FOR(y, y1 + 1, y2) 
        {
            int u = GetId(x1, y);
            int v = GetId(x1, y - 1);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else FOR(x, x1 + 1, x2) 
        {
            int u = GetId(x, y1);
            int v = GetId(x - 1, y1);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    FOR(u, 1, n) 
    {
        sort(all(adj[u]));
        adj[u].erase(unique(all(adj[u])), adj[u].end());
    }

    FOR(u, 1, n) if (!visited[u]) DFS(u, -1, ++cc);
    FOR(u, 1, n) for (auto &v : adj[u]) deg[u]++;
    
    int res = 0;
    FOR(i, 1, cc)
    {
        int cnt = 0;
        for (auto &u : ccNodes[i]) cnt += (deg[u] & 1);
        if (cnt == 0) res++;
        else res += cnt / 2;

        // cout << "CC " << i << ": ";
        // for (auto &u : ccNodes[i]) cout << u << ' ';
        // cout << "\ncnt: " << cnt << '\n';
    }

    cout << res;

    // int u = id[4 + os][6 + os];
    // for (auto &v : adj[u]) cout << v << ' ';
    // cout << deg[id[4 + os][6 + os]];

    return 0;
}