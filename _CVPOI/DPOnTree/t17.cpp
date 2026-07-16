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

int const N = 2e5 + 5;

int n, q;
vector<int> adj[N];

int up[2 * N][20];
int pos[N];
int timer = 0;

void DFS(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        up[++timer][0] = u;
    }
}

bool cmp(int u, int v)
{
    return pos[u] < pos[v];
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    DFS(1, -1);
    Build();

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}