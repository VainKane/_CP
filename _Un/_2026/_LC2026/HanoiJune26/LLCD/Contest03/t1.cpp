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

struct Edge
{
    int u, v;

    void Input() { cin >> u >> v; }
    int Other(int node) { return node ^ u ^ v; }
};

int n;
vector<int> adj[N];
Edge edges[N];

int sz[N];
bool del[N];

char res[N];

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &id : adj[u]) if (!del[id])
    {
        int v = edges[id].Other(u);
        if (v == p) continue;

        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

int Centroid(int u, int p, int n)
{
    for (auto &id : adj[u]) if (!del[id])
    {
        int v = edges[id].Other(u);
        if (v != p && sz[v] > n / 2) return Centroid(v, u, n);
    }

    return u;
}

void Solve(int u, char ch)
{
    DFSPrepare(u, -1);
    int cent = Centroid(u, -1, sz[u]);

    res[cent] = ch;
    for (auto &id : adj[cent]) if (!del[id])
    {
        int v = edges[id].Other(cent);
        del[id] = 1;
        Solve(v, ch + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        edges[i].Input();
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    Solve(1, 'A');
    FOR(u, 1, n) cout << res[u] << ' ';

    return 0;
}