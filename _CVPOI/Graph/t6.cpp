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

int n, k;
vector<pair<int, int>> adj[N];

int h[N];
long long d[N];

map<long long, int> mp[N];

int res = N;

void DFSPrepare(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        DFSPrepare(v, u);
    }
}

void DFS(int u, int p)
{
    mp[u][d[u]] = h[u];
    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;

        DFS(v, u);
        if (sz(mp[v]) > sz(mp[u])) swap(mp[u], mp[v]);

        for (auto &p : mp[v])
        {
            auto it = mp[u].find(k + 2 * d[u] - p.F);
            if (it != mp[u].end()) mini(res, p.S + it->second - 2 * h[u]);
        }

        for (auto &p : mp[v])
        {
            auto &x = mp[u][p.F];
            if (x == 0) x = p.S;
            else mini(x, p.S);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    h[1] = 1;
    DFSPrepare(1, -1);
    DFS(1, -1);

    cout << (res < N ? res : -1);

    return 0;
}