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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;

int n;
vector<int> adj[N];

int cnt[N], res[N];
int h[N];

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

ii cur;

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    int sz = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);
        if (maxi(sz, out[v] - in[v] + 1)) bigChild[u] = v;
    }

    out[u] = timer;
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        DFS(v, u);
        FOR(i, in[v], out[v]) cnt[h[node[i]]] = 0;
    }

    cur = {0, 0};

    if (bigChild[u]) DFS(bigChild[u], u);
    for (auto &v : adj[u]) if (v != p && v != bigChild[u]) FOR(i, in[v], out[v])
        maxi(cur, {++cnt[h[node[i]]], -h[node[i]]});

    maxi(cur, {++cnt[h[u]], -h[u]});
    res[u] = -cur.S - h[u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);
    FOR(u, 1, n) cout << res[u] << '\n';

    return 0;
}