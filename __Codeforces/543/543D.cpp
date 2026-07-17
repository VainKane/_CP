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
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int f[N], g[N];
int pre[N], suf[N];

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return res;
}

void DFSPrepare(int u, int p)
{
    f[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        f[u] = 1LL * f[u] * (f[v] + 1) % MOD;
    }
}

void DFS(int u, int p)
{
    vector<int> nodes = {0};
    for (auto &v : adj[u]) if (v != p) nodes.push_back(v);

    int m = sz(nodes) - 1;
    suf[m + 1] = 1;
    
    FOR(i, 1, m) pre[i] = 1LL * pre[i - 1] * (f[nodes[i]] + 1) % MOD;
    FORD(i, m, 1) suf[i] = 1LL * suf[i + 1] * (f[nodes[i]] + 1) % MOD;

    FOR(i, 1, m)
    {
        int &v = nodes[i];

        g[v] = (1LL * pre[i - 1] * suf[i + 1]) % MOD;
        g[v] = (1LL * g[u] * g[v] + 1) % MOD;
    }

    for (auto &v : adj[u]) if (v != p) DFS(v, u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    pre[0] = g[1] = 1;

    DFSPrepare(1, -1);
    DFS(1, -1);

    FOR(u, 1, n) cout << 1LL * f[u] * g[u] % MOD << ' ';

    return 0;
}