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

struct Edge
{
    int u, v, w;
};

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

int n, m;

Edge edges[N];
vector<int> adj[N];
vector<int> dagAdj[N];

int inDeg[N];
vector<int> topo;

int dp[N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!inDeg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for (auto &v : dagAdj[u]) if (!--inDeg[v]) q.push(v);
    }

    assert(sz(topo) == n);
}

bool Check(Edge a, Edge b)
{
    if (a.w + 1 != b.w) return false;
    return (a.u == b.u || a.u == b.v ||
            a.v == b.u || a.v == b.v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    // FOR(u, 1, m) FOR(v, 1, m) if (Check(edges[u], edges[v]))
    // {
    //     dagAdj[u].push_back(v);
    //     inDeg[v]++;
    // }

    FOR(i, 1, n) for (auto &u : adj[i]) for (auto &v : adj[i])
    {
        if (edges[u].w + 1 != edges[v].w) continue;
        dagAdj[u].push_back(v);
        inDeg[v]++;
    }

    BFS();
    FOR(u, 1, m) dp[u] = 1;

    int res = 0;
    for (auto &u : topo) 
    {
        Add(res, dp[u]);
        for (auto &v : dagAdj[u]) Add(dp[v], dp[u]);
    }
    
    cout << res;

    // FOR(u, 1, m)
    // {
    //     cout << "Adj of " << u << ":\n";
    //     for (auto &v : dagAdj[u]) cout << v << ' ';
    //     cout << '\n';
    // }

    return 0;
}