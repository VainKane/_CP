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

int n;

int a[N];
vector<int> adj[N];
vector<int> revAdj[N];

int deg[N];
int revDeg[N];

long long cntFrom[N];
long long cntTo[N];

vector<int> topo;

void BFS(vector<int> adj[], int deg[])
{
    queue<int> q;
    FOR(u, 1, n) if (deg[u] == 0) q.push(u);

    topo.clear();

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto &v : adj[u]) if (!--deg[v]) q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        revAdj[v].push_back(u);

        deg[v]++; revDeg[u]++;
    }

    BFS(adj, deg);
    for (auto &u : topo) for (auto &v : adj[u]) cntTo[v] += cntTo[u] + a[u];

    BFS(revAdj, revDeg);
    for (auto &u : topo) for (auto &v : revAdj[u]) cntFrom[v] += cntFrom[u] + a[u];

    long long res = 0;

    FOR(u, 1, n) for (auto &v : adj[u])
    {
        long long x = cntTo[v] + a[v] - cntTo[u] - a[u];
        long long y = cntFrom[u] + a[u] - cntFrom[v] - a[v];
        maxi(res, x * y);
    }

    FOR(u, 1, n) res += 1LL * a[u] * (cntFrom[u] + a[u] - 1);
    cout << res;

    return 0;
}