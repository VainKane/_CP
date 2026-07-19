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

int const N = 2e5 + 5;

int n;

int c[N];
vector<int> adj[N];

int sz[N];
bool del[N];

vector<ii> centAdj[N];
int minD[N];
int res;

void DFSPreapre(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        DFSPreapre(v, u);
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
    DFSPreapre(u, -1);
    int cent = Centroid(u, -1, sz[u]);

    DFS(cent, -1, cent);
    del[cent] = 1;

    for (auto &v : adj[cent]) if (!del[v]) Solve(v);
}

void Reset()
{
    FOR(u, 1, n)
    {
        adj[u].clear();
        centAdj[u].clear();
        
        del[u] = 0;
        minD[u] = N;
    }

    res = N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> c[1];
        FOR(i, 2, n) cin >> c[i];

        Reset();
        FOR(i, 2, n)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solve(1);
        for (auto &p : centAdj[c[1]]) mini(minD[p.F], p.S);

        FOR(i, 2, n)
        {
            for (auto &p : centAdj[c[i]])
            {
                mini(res, p.S + minD[p.F]);
                mini(minD[p.F], p.S);
            }

            cout << res << ' ';
        }

        cout << '\n';
    }

    return 0;
}