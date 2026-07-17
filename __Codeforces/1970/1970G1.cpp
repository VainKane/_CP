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

int const N = 1e5 + 5;
long long const oo = 1e18;

int n, m, c;
vector<int> adj[N];

int f[N];
int h[N];

void DFS(int u, int p)
{
    f[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);
        f[u] += f[v];
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> c;

        FOR(u, 1, n) adj[u].clear();
        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFS(1, -1);

        long long res = oo;
        FOR(u, 1, n) for (auto &v : adj[u]) if (h[u] < h[v])
        {
            int cnt = n - f[v];
            mini(res, 1LL * f[v] * f[v] + 1LL * cnt * cnt);
        }

        cout << res << '\n';
    }

    return 0;
}