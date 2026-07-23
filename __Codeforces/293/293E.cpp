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

struct FenwickTree
{
    vector<vector<int>> bit;
}

int n, l, c;
vector<ii> adj[N];

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

int h[N], d[N];

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    int sz = 0;

    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p) continue;

        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFSPrepare(v, u);
        if (maxi(sz, out[v] - in[v])) bigChild[u] = v;
    }

    out[u] = timer;
}

void DFS(int u, int p)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> c;
    FOR(i, 2, n)
    {
        int p, w;
        cin >> p >> w;
        adj[i].push_back({p, w});
        adj[p].push_back({i, w});
    }

    return 0;
}