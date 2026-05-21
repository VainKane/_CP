#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define BIT(i, mask) ((mask >> (i)) & 1)
#define MK(i) (1 << (i))
#define F first
#define S second
#define name "lck"

int const N = 7e4 + 5;
int const LOG = 19;

int n, q;
vector<int> adj[N];

int cnt = 0;

int h[N];
int lg[N];

int in[N];
int up[N][LOG];
pair<int, int> st[N][LOG];

bool cmp (int u, int v) { return in[u] < in[v]; }

void DFS(int u)
{
    in[u] = ++cnt;
    st[u][0] = {u, u};

    for (auto v : adj[u]) 
    {
        if (v == up[u][0]) continue;
        
        up[v][0] = u;
        h[v] = h[u] + 1;

        DFS(v);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];

    FOR(i, 0, lg[d]) if (BIT(i, d)) u = up[u][i];
    if (u == v) return u;

    for (int i = lg[n]; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

pair<int, int> Get(int l, int r)
{
    int k = lg[r - l + 1];
    int mi = min(st[l][k].F, st[r - MK(k) + 1][k].F, cmp);
    int ma = max(st[l][k].S, st[r - MK(k) + 1][k].S, cmp);

    return {mi, ma};
}

void Init()
{
    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;
    DFS(1);

    FOR(i, 1, lg[n]) FOR(u, 1, n) 
    {
        st[u][i].F = min(st[u][i - 1].F, st[u + MK(i - 1)][i - 1].F, cmp);
        st[u][i].S = max(st[u][i - 1].S, st[u + MK(i - 1)][i - 1].S, cmp);

        up[u][i] = up[up[u][i - 1]][i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Init();

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        pair<int, int> p = Get(u, v);
        cout << LCA(p.F, p.S) << '\n';
    }

    return 0;
}