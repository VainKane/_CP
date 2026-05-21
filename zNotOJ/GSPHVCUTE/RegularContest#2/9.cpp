#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define F first
#define S second

struct Edge
{
    int v, w;
};

int const N = 3e5 + 5;

int n, q;
vector<Edge> adj[N];
pair<int, int> edg[N];

vector<int> child[N];
long long d[N];

bool isLeaf[N];

int qr[N];
bool mark[N];

int par[N], sz[N];
long long val[N];

long long res[N];

void MakeSet()
{
    FOR(i, 1, n)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int v)
{
    if (v == par[v]) return v;
    return par[v] = Find(par[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;
    sz[b] += sz[a];
    val[a] = min(val[a], val[b]);
}

void DFS(int u, int p)
{
    bool isLeaf = true;

    for (auto e : adj[u]) if (e.v != p)
    {
        d[e.v] = d[u] + e.w;
        isLeaf = false;
        DFS(e.v, u); 
    }

    val[u] = (isLeaf ? d[u] : 1e18);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int p, c; 
        cin >> p >> c;
        
        adj[p].push_back({i, c});
        adj[i].push_back({p, c});

        edg[i] = {i, p};
    }

    FOR(i, 1, q)
    {
        cin >> qr[i];
        mark[qr[i]] = true;
    }

    MakeSet();
    DFS(1, -1);

    // FOR(u, 1, n) cout << u << ' ' << val[u] << '\n';

    FOR(i, 2, n) if (!mark[i]) Union(edg[i].F, edg[i].S);
    FORD(i, q, 1)
    {
        res[i] = val[Find(1)];
        if (res[i] == 1e18) res[i] = -1;

        Union(edg[qr[i]].F, edg[qr[i]].S);
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}