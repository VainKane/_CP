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
#define name "maxflow"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const LOG = 20;

int n, k;
vector<int> adj[N];

int up[2 * N][LOG];
int pos[N], par[N];
int timer = 0;

int f[N];

bool cmp(int u, int v) { return pos[u] < pos[v]; }
void DFSPrepare(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        par[v] = u;
        DFSPrepare(v, u);
        up[++timer][0] = u;
    }
}

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] += f[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".in", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    Build();

    FOR(i, 1, k)
    {
        int u, v, p;
        cin >> u >> v;
    
        p = LCA(u, v);
        f[u]++, f[v]++, f[p]--, f[par[p]]--;
    }

    DFS(1, -1);
    cout << *max_element(f + 1, f + n + 1);

    return 0;
}