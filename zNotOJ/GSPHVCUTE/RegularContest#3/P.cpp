#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "business"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;
int const oo = N + 1;

int n, k;

vector<int> topo;

vector<int> adj[N];
vector<int> children[N];

int d[N];
int f[N], g[N];

queue<int> q;

void BFS()
{
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) if (mini(d[v], d[u] + 1)) q.push(v);
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        children[u].push_back(v);
    }
    topo.push_back(u);
}

bool Check(int l)
{
    bool placed = false;

    REP(i, n)
    {
        int u = topo[i];

        f[u] = d[u] <= l ? -oo : 0;
        g[u] = d[u] == 0 ? 0 : +oo;

        for (auto &v : children[u]) 
        {
            maxi(f[u], f[v] + 1);
            mini(g[u], g[v] + 1);
        }
        
        if (f[u] + g[u] <= l) f[u] = -oo;
        else if (f[u] == l || u == 1)
        {
            if (placed) return false;

            f[u] = -oo;
            g[u] = 0;
            placed = true;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    memset(d, 0x3f, sizeof d);

    cin >> n >> k;
    FOR(i, 1, k) 
    {
        int p; cin >> p;
        q.push(p);
        d[p] = 0;
    }
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS();
    DFS(1, -1);

    int l = 0;
    int r = n - 1;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (Check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}