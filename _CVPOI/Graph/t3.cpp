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
vector<pair<int, int>> adj[N];

int d[N];
long long f[N][2];

void DFSPrepare(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        d[v] = d[u] ^ w;
        DFSPrepare(v, u);
    }
}

void DFS(int u, int p)
{
    f[u][d[u]] = 1;
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        DFS(v, u);
        REP(i, 2) f[u][i] += f[v][i];
    }
}

long long C2(int x)
{
    if (x < 2) return 0;
    return 1LL * x * (x - 1) / 2;
}

long long Get(int cnt0, int cnt1)
{
    return abs(C2(cnt0) + C2(cnt1) - 1LL * cnt0 * cnt1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        w &= 1;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    long long res = Get(f[1][0], f[1][1]);

    FOR(v, 2, n)
    {
        long long haha = f[v][0] - f[v][1];
        mini(res, Get(f[1][0] - haha, f[1][1] + haha));
    }
    
    cout << res;
 
    return 0;
}