#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5e4 + 5;
int const LOG = 16;
int const BK = 223;

int n, q;
vector<int> adj[N];
vector<int> c[N];

int up[N][20];
int h[N];

int cnt[N];

int id[N];
int d[N / BK + 5][N];
int timer = 0;

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;
        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int Query1(int u, int x)
{
    int res = n;
    for (auto &v : c[x]) mini(res, h[u] + h[v] - 2 * h[LCA(u, v)]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        c[x].push_back(i);
        cnt[x]++;
    }

    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);
    h[0] = -1;

    while (q--)
    {
        int u, x;
        cin >> u >> x;

        if (!cnt[x]) cout << "-1\n"; 
        else cout << Query1(u, x) << '\n';
    }

    return 0;
}