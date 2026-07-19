#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;
int const oo = N + 1;

int n, m;
bool boom[N];

vector<int> adj[N];
vector<int> children[N];

vector<int> topo;
int f[N], g[N];

int Cal(int l)
{
    int cnt = 0;
    REP(i, n)
    {
        int u = topo[i];

        f[u] = boom[u] ? 0 : -oo;
        g[u] = oo;

        for (auto v : children[u])
        {
            maxi(f[u], f[v] + 1); 
            mini(g[u], g[v] + 1);
        }

        if (f[u] + g[u] <= l) f[u] = -oo;
        else if (f[u] == l || u == 1)
        {
            f[u] = -oo;
            g[u] = 0;
            cnt++;
        }
    }
    return cnt;
}

void DFS(int u, int p)
{
    for (auto v : adj[u]) if (v != p)
    {
        children[u].push_back(v);
        DFS(v, u);
    }
    topo.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> boom[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    DFS(1, -1);

    int l = 0;
    int r = n - 1;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        
        if (Cal(mid) <= m)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}