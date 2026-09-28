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
#define name "TRAVEL"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const LOG = 20;

int n, q;
vector<ii> adj[N];

int up[LOG][2 * N];
int pos[N], h[N];
int timer = 0;

ll d[N];

bool cmp(int u, int v) { return pos[u] < pos[v]; }

void DFS(int u, int p)
{
    up[0][++timer] = u;
    pos[u] = timer;

    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p) continue;
        
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFS(v, u);
        up[0][++timer] = u;
    }
}

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[j][i] = min(up[j - 1][i], up[j - 1][i + MK(j - 1)], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[k][u], up[k][v - MK(k) + 1], cmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1);
    Build();

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int p = LCA(u, v);
        cout << d[u] + d[v] - 2 * d[p] + h[u] + h[v] - 2 * h[p] + 1 << '\n';
    }

    return 0;
}