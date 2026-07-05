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

int const N = 1e5 + 5;

int n, q;
vector<int> adj[N];
vector<ii> centAdj[N];

int sz[N];
bool del[N];
int minD[N];

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

int Centroid(int u, int p, int n)
{
    for (auto &v : adj[u]) if (v != p && !del[v] && sz[v] > n / 2) return Centroid(v, u, n);
    return u;
}

void DFS(int u, int p, int cent, int h = 0)
{
    centAdj[u].push_back({cent, h});
    for (auto &v : adj[u]) if (v != p && !del[v]) DFS(v, u, cent, h + 1);
}

void Solve(int u)
{
    DFSPrepare(u, -1);
    int cent = Centroid(u, -1, sz[u]);

    DFS(cent, -1, cent);
    del[cent] = 1;

    for (auto &v : adj[cent]) if (!del[v]) Solve(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(minD, 0x3f, sizeof minD);
    Solve(1);
    
    for (auto &p : centAdj[1]) mini(minD[p.F], p.S);
    while (q--)
    {
        int type, u;
        cin >> type >> u;

        if (type == 1) for (auto &p : centAdj[u]) mini(minD[p.F], p.S);
        else
        {
            int res = N;
            for (auto &p : centAdj[u]) mini(res, minD[p.F] + p.S);
            cout << res << '\n';
        }
    }

    return 0;
}