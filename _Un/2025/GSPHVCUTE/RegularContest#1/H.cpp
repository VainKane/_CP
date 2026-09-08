#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define F first
#define S second
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define name "egalitarianism3"

struct Edge
{
    int v, w;
};

int const N = 55;

int n;
vector<Edge> adj[N];
vector<pair<int, int>> nodes[N];
vector<int> res;

int d[N];
int par[N];

void DFS(int u, int id)
{
    nodes[id].pb({d[u], u});
    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (v == par[u]) continue;
        d[v] = d[u] + w;
        par[v] = u;
        DFS(v, id);
    }
}

void Cal(int p)
{  
    memset(par, 0, sizeof par);
    vector<int> dist;
    
    for (auto e : adj[p])
    {
        int v = e.v;
        int w = e.w;

        nodes[v].clear();
        d[v] = w;
        par[v] = p;
        DFS(v, v);

        sort(all(nodes[v]));
        nodes[v].erase(unique(all(nodes[v])), nodes[v].end());
        
        for (auto p : nodes[v]) dist.pb(p.F);
    }

    sort(all(dist));
    dist.erase(unique(all(dist)), dist.end());

    for (auto x : dist)
    {
        vector<int> tmp;

        for (auto e : adj[p])
        {
            int v = e.v;
            int idx = lower_bound(all(nodes[v]), mp(x, 0)) - nodes[v].begin();

            if (idx == sz(nodes[v])) continue;
            if (nodes[v][idx].F == x) tmp.pb(nodes[v][idx].S);
        }

        if (tmp.size() > res.size()) res = tmp;
    }
}

int main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (int i = 1; i <= n; i++) Cal(i);

    if (res.size() <= 1) 
    {
        res = {1};
        if (n >= 2) res = {1, 2};
    }

    cout << res.size() << '\n';
    for (auto v : res) cout << v << ' ';

    return 0;
}