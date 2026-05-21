#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "CEDGE"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
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

int const N = 1e5 + 5;

int n, m;

Edge edges[N];
vector<int> adj[N];

int in[N], low[N];
int timer = 0;

bool visited[N];
bool bridge[N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;

    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u); 

        if (v == p) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);

            if (low[v] == in[v]) bridge[id] = true;
        }
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u);
        if (!visited[v]) DFS(v);
    }  
}

bool Check(int &id)
{
    memset(visited, false, (n + 1));
    visited[edges[id].u] = visited[edges[id].v] = true;
    
    FOR(u, 1, n) if (!visited[u])
    {
        DFS(u);
        break;
    }

    FOR(u, 1, n) if (!visited[u]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;

        edges[i] = {u, v};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    Tarjan(1, -1);

    int res = 0;
    
    FOR(i, 1, m)
    {
        if (bridge[i]) res += sz(adj[edges[i].u]) > 1 && sz(adj[edges[i].v]) > 1;
        else res += Check(i);

        // if (bridge[i])
        // {
        //     if (sz(adj[edges[i].u]) > 1 || sz(adj[edges[i].v]) > 1) cout << i << ' ';
        // }
        // else if (Check(i)) cout << i << ' ';
    }

    cout << res;

    return 0;
}