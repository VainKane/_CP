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

int const N = 22;
int const MOD = 998244353;
int const LOG = 10;

int n, q;
vector<int> adj[N];

int up[N][15];
int h[N];

int f[N];
bool visited[N];

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFSPrepare(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);

    FORD(i, LOG, 0) if (up[u][i] && h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void DFS1(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS1(v, u);
        f[u] += f[v];
    }
}

void DFS2(int u, int p, int &mask)
{
    visited[u] = true;
    for (auto &v : adj[u]) if (BIT(v - 1, mask) && v != p) DFS2(v, u, mask);
}

void Reset()
{
    FOR(u, 1, n)
    {
        memset(up[u], 0, sizeof up[u]);
        adj[u].clear();
    }
}

bool Check(int mask)
{
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        if (!visited[i + 1]) return false;
    }

    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        if (f[i + 1]) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> q;

        Reset();
        FOR(i, 2, n)
        {
            int p; cin >> p;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }

        DFSPrepare(1, -1);

        while (q--)
        {
            int u, v;
            cin >> u >> v;

            int p = LCA(u, v);
            memset(f, 0, sizeof f);

            f[u]++; f[v]++;
            f[p]--; f[up[p][0]]--;
        
            DFS1(1, -1);
        
            int res = 0;
            REP(mask, MK(n)) if (mask)
            {
                memset(visited, false, sizeof visited);
                DFS2(__builtin_ctz(mask) + 1, -1, mask);
                res += Check(mask);
            }

            cout << res << '\n';
        }
    }

    return 0;
}