#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int u, v;

    int GetOther(int p)
    {
        return p ^ u ^ v;
    }
};

int const N = 509;
int const M = 1e5 + 5;

int n, m;
vector<int> adj[N];
Edge edges[M];

bool visited[N];
bool inCircle[N];

bool DFS(int u, int banned)
{
    inCircle[u] = visited[u] = true;
    
    for (auto &id : adj[u]) if (id != banned) 
    {
        int v = edges[id].GetOther(u);
        if (inCircle[v]) return true;
        if (visited[v]) continue;
        if (DFS(v, banned)) return true;
    }

    inCircle[u] = false;
    return false;
}

bool Solve()
{
    FOR(i, 1, m)
    {
        memset(visited, false, sizeof visited);
        memset(inCircle, false, sizeof inCircle);

        bool ok = true;
        FOR(u, 1, n) if (!visited[u]) if (DFS(u, i)) 
        {
            ok = false;
            break;
        }

        if (ok) return true;
    }
    return false;
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
        edges[i] = {u, v};
        adj[u].push_back(i);
    }

    cout << (Solve() ? "YES" : "NO");

    return 0;
}